#include "mod.h"
#include "patch.h"

#include <wii/OSError.h>
#include <wii/string.h>

#include <spm/mario.h>
#include <spm/mario_hit.h>
#include <spm/mario_motion.h>
#include <spm/system.h>
#include <spm/mario_pouch.h>
#include <spm/camdrv.h>
#include <spm/seqdrv.h>
#include <spm/npcdrv.h>

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
		writeBranch(spm::mario::getInitSpeed_o, 0, spm::mario::getInitSpeed);
		writeBranch(spm::mario::getMaxSpeed_o, 0, spm::mario::getMaxSpeed);
		writeBranch(spm::mario::calcSpeed_o, 0, spm::mario::calcSpeed);
		writeBranch(spm::mario::getCrouchState_o, 0, spm::mario::getCrouchState);
		writeBranch(spm::mario::isSuperJumpHitCeiling_o, 0, spm::mario::isSuperJumpHitCeiling);
		writeBranch(spm::mario::marioCtrlOffChk_o, 0, spm::mario::marioCtrlOffChk);
		writeBranch(spm::mario::marioKeyOffChk_o, 0, spm::mario::marioKeyOffChk);
		writeBranch(spm::mario::marioCtrlOff_o, 0, spm::mario::marioCtrlOff);
		writeBranch(spm::mario::marioCtrlOn_o, 0, spm::mario::marioCtrlOn);
		writeBranch(spm::mario::marioKeyOff_o, 0, spm::mario::marioKeyOff);
		writeBranch(spm::mario::marioKeyOn_o, 0, spm::mario::marioKeyOn);
		writeBranch(spm::mario::marioSoundInit_o, 0, spm::mario::marioSoundInit);
		
		writeBranch(spm::mario_pouch::pouchGetPtr_o, 0, spm::mario_pouch::pouchGetPtr);
		writeBranch(spm::mario_pouch::pouchGetTotalCoinsCollected_o, 0, spm::mario_pouch::pouchGetTotalCoinsCollected);
		writeBranch(spm::mario_pouch::pouchSetCoin_o, 0, spm::mario_pouch::pouchSetCoin);
		writeBranch(spm::mario_pouch::pouchAddCoin_o, 0, spm::mario_pouch::pouchAddCoin);
		writeBranch(spm::mario_pouch::pouchSetAttack_o, 0, spm::mario_pouch::pouchSetAttack);
		writeBranch(spm::mario_pouch::pouchAddAttack_o, 0, spm::mario_pouch::pouchAddAttack);
		writeBranch(spm::mario_pouch::pouchSetHp_o, 0, spm::mario_pouch::pouchSetHp);
		writeBranch(spm::mario_pouch::pouchAddHp_o, 0, spm::mario_pouch::pouchAddHp);
		
		writeBranch(spm::system::getSpmarioDVDRoot_o, 0, spm::system::getSpmarioDVDRoot);
		writeBranch(spm::system::compAngle_o, 0, spm::system::compAngle);
		writeBranch(spm::system::reviseAngle_o, 0, spm::system::reviseAngle);
		writeBranch(spm::system::angleABf_o, 0, spm::system::angleABf);
		writeBranch(spm::system::distABf_o, 0, spm::system::distABf);
		writeBranch(spm::system::rand_o, 0, spm::system::rand);
		writeBranch(spm::system::irand_o, 0, spm::system::irand);
		writeBranch(spm::system::frand_o, 0, spm::system::frand);
		
		writeBranch(spm::seqdrv::seqGetSeq_o, 0, spm::seqdrv::seqGetSeq);
		writeBranch(spm::seqdrv::seqSetSeq_o, 0, spm::seqdrv::seqSetSeq);
		writeBranch(spm::seqdrv::seqMain_o, 0, spm::seqdrv::seqMain);
		writeBranch(spm::seqdrv::seqInit_SPMARIO_o, 0, spm::seqdrv::seqInit_SPMARIO);

		writeBranch(spm::mario_motion::marioMotion_o, 0, spm::mario_motion::marioMotion);

		writeBranch(spm::npcdrv::npcInit_o, 0, spm::npcdrv::npcInit);
		writeBranch(spm::npcdrv::npcReset_o, 0, spm::npcdrv::npcReset);
		writeBranch(spm::npcdrv::npcWorkSetFlag2_o, 0, spm::npcdrv::npcWorkSetFlag2);
	}
}