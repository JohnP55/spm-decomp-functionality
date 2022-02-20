#include "spm/mario_hit.h"
#include "spm/mario.h"
#include "spm/hitdrv.h"
#include <wii/types.h>

namespace spm::mario_hit {

/*float FUN_80135cb0()
{
	mario::MarioWork* marioWork = mario::marioGetPtr();
	
	float x = (marioWork->position).x;
	float y = (marioWork->position).y;
	float z = (marioWork->position).z;
	
	float local_78 = -10000.0;
	float hitboxHeight = marioWork->scaledHitboxHeight;
	
	float ySpd = marioWork->flags & 0x10000 ? (marioWork->jumpFallPara).speedY : 0.0;

	s32 crouchState = mario::getCrouchState();

	if (!(marioWork->miscFlags & mario::DOTTIE_SMALL))
		hitboxHeight *= (marioWork->scale).y;

	if (marioWork->state == mario::LUIGI_CROUCH)
		if (!mario::isSuperJumpHitCeiling())
			hitboxHeight += 5.0;
		
	else if (!(marioWork->miscFlags & mario::SWIM_SPACE))
	{
		if (crouchState == 2 && marioWork->flags & 0x2000000)
			hitboxHeight *= 0.4;
	}
	else
	{
		float spaceYSpdRelatedDelta = (marioWork->spaceYSpdRelated).x * (marioWork->spaceYSpdRelated).z;
		ySpd = (marioWork->spaceMovementDir).y * marioWork->accelerationSpeed + spaceYSpdRelatedDelta;
		
		if (ySpd < 1.0)
			ySpd = 1.0;
	}

	marioWork->hitObjs1[6] = mario::FUN_80136eec(ySpd, &x, &hitboxHeight, &local_78);
	
	Vec3 gravDotProductVec;
	mario::getGravityDotProduct(&marioWork->position, &gravDotProductVec);
	
	if (!(marioWork->miscFlags & mario::SWIM_SPACE))
	{
		if (crouchState == 2 && marioWork->flags & 0x2000000)
			hitboxHeight *= 0.4;
		hitboxHeight = (marioWork->scale).y * hitboxHeight;
	}
}*/
}