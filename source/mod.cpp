#include "mod.h"
#include "patch.h"

#include <wii/OSError.h>
#include <wii/string.h>

#include <spm/mario.h>
#include <spm/system.h>
#include <spm/mario_pouch.h>

namespace mod {

	/*
		General mod functions
	*/

	void main()
	{
		wii::OSError::OSReport("SPM Rel Loader: the mod has ran!\n");
		
		writeBranch(spm::mario::marioSpawnPlayer_o, 0, spm::mario::marioSpawnPlayer);
		writeBranch(spm::mario::marioGetGravity_o, 0, spm::mario::marioGetGravity);
		writeBranch(spm::mario::marioGetPtr_o, 0, spm::mario::marioGetPtr);
		
		writeBranch(spm::mario_pouch::pouchGetPtr_o, 0, spm::mario_pouch::pouchGetPtr);
		writeBranch(spm::mario_pouch::pouchGetTotalCoinsCollected_o, 0, spm::mario_pouch::pouchGetTotalCoinsCollected);
		writeBranch(spm::mario_pouch::pouchSetCoin_o, 0, spm::mario_pouch::pouchSetCoin);
		writeBranch(spm::mario_pouch::pouchAddCoin_o, 0, spm::mario_pouch::pouchAddCoin);
		writeBranch(spm::mario_pouch::pouchSetAttack_o, 0, spm::mario_pouch::pouchSetAttack);
		writeBranch(spm::mario_pouch::pouchAddAttack_o, 0, spm::mario_pouch::pouchAddAttack);
		
		writeBranch(spm::system::compAngle_o, 0, spm::system::compAngle);
		writeBranch(spm::system::rand_o, 0, spm::system::rand);
		writeBranch(spm::system::irand_o, 0, spm::system::irand);
		writeBranch(spm::system::frand_o, 0, spm::system::frand);
	}
}