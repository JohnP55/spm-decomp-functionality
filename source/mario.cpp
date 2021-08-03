#include "spm/mario.h"
#include <wii/types.h>

namespace spm::mario
{
	
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
		float unkProp;

		if ((marioWork.flag0 & 0x40000000) != 0) { // Mega Star
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
			unkProp = characterProperties[curCharacter].unk * 1.5;
		}
		else if ((marioWork.flag4 & 0x4000) != 0) { // Dottie
			hWidth = 7.5;

			if (marioWork.character == PLAYER_BOWSER) hHeight = 7.5;
			else hHeight = 5.0;

			initSpeed = characterProperties[curCharacter].initSpeed;
			maxSpeed = characterProperties[curCharacter].maxSpeed;
			unkProp = characterProperties[curCharacter].unk;
		}
		else { // Normal
			hWidth = characterProperties[curCharacter].hitboxWidth;
			hHeight = characterProperties[curCharacter].hitboxHeight;

			initSpeed = characterProperties[curCharacter].initSpeed;
			maxSpeed = characterProperties[curCharacter].maxSpeed;
			unkProp = characterProperties[curCharacter].unk;

			marioWork.flag0 = marioWork.flag0 & 0x7fffffff;

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
		marioWork.unkProp = unkProp;
		
		if ((marioWork.flag0 & 0x2000000) != 0) {
			marioWork.scaledHitboxWidth = marioWork.hitboxWidth * 0.4;
			marioWork.scaledHitboxHeight = marioWork.hitboxHeight * 0.4;
		}

		FUN_8013146c();
		return;
	}
}