#include "mod.h"
#include "patch.h"

#include <spm/fontmgr.h>
#include <spm/seqdrv.h>
#include <spm/seqdef.h>
#include <wii/OSError.h>
#include <wii/string.h>

#include <spm/mario.h>
#include <spm/system.h>
#include <spm/mario_pouch.h>

namespace mod {

	/*
		Title Screen Custom Text
		Prints "SPM Rel Loader" at the top of the title screen
	*/

	static spm::seqdef::SeqFunc *seq_titleMainReal;
	static void seq_titleMainOverride(spm::seqdrv::SeqWork *wp)
	{
		wii::RGBA green{ 0, 255, 0, 255 };
		f32 scale = 0.8f;
		const char * msg = "SPM Rel Loader";
		spm::fontmgr::FontDrawStart();
		spm::fontmgr::FontDrawEdge();
		spm::fontmgr::FontDrawColor(&green);
		spm::fontmgr::FontDrawScale(scale);
		spm::fontmgr::FontDrawNoiseOff();
		spm::fontmgr::FontDrawRainbowColorOff();
		f32 x = -((spm::fontmgr::FontGetMessageWidth(msg) * scale) / 2);
		spm::fontmgr::FontDrawString(x, 200.0f, msg);
		seq_titleMainReal(wp);
	}
	static void titleScreenCustomTextPatch()
	{
		seq_titleMainReal = spm::seqdef::seq_data[spm::seqdrv::SEQ_TITLE].main;
		spm::seqdef::seq_data[spm::seqdrv::SEQ_TITLE].main = &seq_titleMainOverride;
	}

	/*
		General mod functions
	*/

	void main()
	{
		wii::OSError::OSReport("SPM Rel Loader: the mod has ran!\n");
		titleScreenCustomTextPatch();
		
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