#include <spm/mario_motion.h>
#include <spm/mario.h>
#include <spm/mario_hit.h>

namespace spm::mario_motion {
    
void marioMotion()
{
	mario::MarioWork* marioWork = mario::marioGetPtr();
	mario_hit::clear_hitObj_9();
	marioWork->hitObjs2[0] = (HitObj*)0x0;

	do {
		marioMotTbl[marioWork->state].mainFunc(marioWork);
	} while ((marioWork->trigFlags & 1) != 0);
}

}