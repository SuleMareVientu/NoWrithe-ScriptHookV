#include "script.h"

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

	// set ped config flag 2 times a second
	for (int ped = 0; ped < count; ped++)
	{
		PED::SET_PED_CONFIG_FLAG(peds[ped], 281, 1);
	}
	return;
}

void ScriptMain()
{
	SYSTEM::SETTIMERA(0);
	while (true)
	{
		if (SYSTEM::TIMERA() > 500)
		{
			SYSTEM::SETTIMERA(0);
			update();
		}
		WAIT(0);
	}
	return;
}