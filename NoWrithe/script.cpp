#include "script.h"

DWORD	pedUpdateTime;

void update()
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	// check if player ped exists and control is on (e.g. not in a cutscene)
	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !PLAYER::IS_PLAYER_CONTROL_ON(player))
		return;

	// get all peds
	const int ARR_SIZE = 1024;
	Ped peds[ARR_SIZE];
	int count = worldGetAllPeds(peds, ARR_SIZE);

	// set PED_FLAG_NO_WRITHE 2 times a second
	if (pedUpdateTime + 500 < GetTickCount())
	{
		pedUpdateTime = GetTickCount();
		for (int i = 0; i < count; i++)
		{
			if (peds[i] != playerPed)
			{
				PED::SET_PED_CONFIG_FLAG(peds[i], 281, 1);
			}
		}
	}
	return;
}

void main()
{
	while (true)
	{
		update();
		WAIT(0);
	}
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}