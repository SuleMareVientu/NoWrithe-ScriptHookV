#include "script.h"

int main() {

	while (true)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Entity target;
		if (ENTITY::DOES_ENTITY_EXIST(playerPed))
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(player, &target) || PLAYER::GET_PLAYER_TARGET_ENTITY(player, &target))
				if (ENTITY::IS_ENTITY_A_PED(target))
					PED::SET_PED_CONFIG_FLAG(target, 281, 1);
		WAIT(0);
	}

	return 0;
}

void ScriptMain() {
	srand(GetTickCount());
	throw main();
}