#include "spm/mario.h"
#include <wii/types.h>

namespace spm::mario {

s32 marioGetGravity()
{
	return marioWork.gravityType;
}

MarioWork* marioGetPtr()
{
	return &marioWork;
}

void marioSpawnPlayer()
{
	s8 curCharacter = marioWork.character;

	float hWidth;
	float hHeight;

	float initSpeed;
	float maxSpeed;
	float swimmingSpeed;

	if ((marioWork.flags & 0x40000000) != 0) { // Mega Star
		if (marioWork.character == PLAYER_BOWSER) {
			hWidth = 200.0;
			hHeight = 290.0;
		}
		else if (curCharacter == PLAYER_PEACH) {
			hWidth = 150.0;
			hHeight = 275.0;
		}
		else {
			hWidth = 150.0;
			hHeight = 200.0;
		}

		initSpeed = characterProperties[curCharacter].initSpeed * 1.5;
		maxSpeed = characterProperties[curCharacter].maxSpeed * 1.5;
		swimmingSpeed = characterProperties[curCharacter].swimmingSpeed * 1.5;
	}
	else if ((marioWork.miscFlags & 0x4000) != 0) { // Dottie
		hWidth = 7.5;

		if (marioWork.character == PLAYER_BOWSER) hHeight = 7.5;
		else hHeight = 5.0;

		initSpeed = characterProperties[curCharacter].initSpeed;
		maxSpeed = characterProperties[curCharacter].maxSpeed;
		swimmingSpeed = characterProperties[curCharacter].swimmingSpeed;
	}
	else { // Normal
		hWidth = characterProperties[curCharacter].hitboxWidth;
		hHeight = characterProperties[curCharacter].hitboxHeight;

		initSpeed = characterProperties[curCharacter].initSpeed;
		maxSpeed = characterProperties[curCharacter].maxSpeed;
		swimmingSpeed = characterProperties[curCharacter].swimmingSpeed;

		marioWork.flags = marioWork.flags & 0x7fffffff;

		marioWork.scale.x = npcScale.x;
		marioWork.scale.y = npcScale.y;
		marioWork.scale.z = npcScale.z;

		marioWork.unkScale.x = Vec3_8033086c.x;
		marioWork.unkScale.y = Vec3_8033086c.y;
		marioWork.unkScale.z = Vec3_8033086c.z;
	}

	marioWork.hitboxWidth = hWidth;
	marioWork.hitboxHeight = hHeight;
	marioWork.scaledHitboxWidth = hWidth;
	marioWork.scaledHitboxHeight = hHeight;

	marioWork.initSpeed = initSpeed;
	marioWork.maxSpeed = maxSpeed;
	marioWork.swimmingSpeed = swimmingSpeed;
	
	if ((marioWork.flags & 0x2000000) != 0) {
		marioWork.scaledHitboxWidth = marioWork.hitboxWidth * 0.4;
		marioWork.scaledHitboxHeight = marioWork.hitboxHeight * 0.4;
	}

	FUN_8013146c();
	return;
}

f32 getInitSpeed()
{
	MarioWork* marioWork = marioGetPtr();
	float initSpeed = marioWork->initSpeed;
	
	if ((marioWork->miscFlags & CARRIE_RIDE) != 0)
		initSpeed = 2.0;

	return calcSpeed(initSpeed, false);
}

f32 getMaxSpeed()
{
	MarioWork* marioWork = marioGetPtr();
	float maxSpeed = marioWork->maxSpeed;;

	if ((marioWork->miscFlags & CARRIE_RIDE) != 0)
		maxSpeed = 4.0;

	return calcSpeed(maxSpeed, false);
}

f32 calcSpeed(double speed, bool scaleSpeed)
{
	MarioWork* marioWork = marioGetPtr();
	
	if ((marioWork->miscFlags & DOTTIE_SMALL) != 0)
		speed *= 0.75;
	
	if ((marioWork->miscFlags & SWIMMING) == 0) {
		if (((marioWork->flags & 0x2000000) != 0) || ((marioWork->miscFlags & 0x800) != 0)) {
			speed *= 0.5;
		}
	}
	else {
		if (marioWork->state != 0x2b) {
			speed *= 0.5;
		}
	}
	
	if (scaleSpeed && marioWork->initSpeedScale != 0.0)
		speed *= marioWork->initSpeedScale;
	
	return speed * marioWork->speedScale;
}

/*void setPseudoJoystick()
{
	
}*/

s32 isSuperJumpHitCeiling() // Not really in this file but there's no assert strings close that make sense
{
	MarioWork* marioWork = marioGetPtr();
	return marioWork->state == LUIGI_CROUCH && marioWork->subState > 0x28 && marioWork->subState < 0x31;
}

s32 getCrouchState()
{
	s32 state = 0;
	
	MarioWork* marioWork = marioGetPtr();
	if (marioWork->state == CROUCH)
	{
		state++;
		if (marioWork->subState == 0x14)
			state++;
	}
	return state;
}

u8 marioCtrlOffChk()
{
	return marioWork.ctrl;
}

u8 marioKeyOffChk()
{
	return marioWork.keyOff;
}

u8 marioCtrlOff()
{
	marioWork.ctrl++;
	marioWork.flags |= 2;
	return marioWork.ctrl;
}

u8 marioCtrlOn()
{
	marioWork.ctrl--;
	if (marioWork.ctrl == 0)
		marioWork.flags &= 0xfffffffd;
	return marioWork.ctrl;
}

u8 marioKeyOff()
{
	marioWork.keyOff++;
	marioWork.flags |= 8;
	marioWork.accelerationSpeed = 0.0;
	marioWork.scalarSpeed = 0.0;
	return marioWork.keyOff;
}

u8 marioKeyOn()
{
	marioWork.keyOff--;
	if (marioWork.keyOff == 0)
		marioWork.flags &= 0xfffffff7;
	return marioWork.keyOff;
}

}