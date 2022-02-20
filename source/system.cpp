#include "spm/system.h"

#include <wii/types.h>
#include <wii/math.h>

namespace spm::system
{
	float f_abs(float n)
	{
		return n < 0 ? n * -1 : n;
	}
	
	s32 i_abs(s32 i)
	{
		return i < 0 ? i * -1 : i;
	}
	
	const char* getSpmarioDVDRoot()
	{
		return ".";
	}
	
	float compAngle(float angle1, float angle2)
	{
		if (f_abs(angle2 - angle1) >= 180.0)
		{
			if (angle1 <= angle2)
			{
				angle2 -= 360.0;
			}
			else
			{
				angle2 += 360.0;
			}
		}
		return angle2 - angle1;
	}
	
	// Credits to Seeky
	float reviseAngle(float angle) {
		angle = (float) math::fmod(angle, 360.0);

		// Seems impossible, maybe true if NaN returned?
		if (angle != angle)
			angle = 0.0f;
		
		// Convert negative angles to positive
		if (angle < 0.0f)
		{
			angle += 360.0f;

			// Seems impossible?
			if (angle >= 360.0f)
				angle = 0.0f;
		}

		return angle;
	}
	
	float distABf(float x1, float y1, float x2, float y2)
	{
		return math::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	}
	
	/* float angleABf(float x1, float y1, float x2, float y2)
	{
		float deltaX = x2 - x1;
		float deltaY = y2 - y1;
		
		float absDeltaX = f_abs(deltaX);
		float absDeltaY = f_abs(deltaY);
		
		float angle;
		
		if (absDeltaX <= absDeltaY)
		{
			angle = 0.0;
			
			if (absDeltaY != 0.0)
			{
				absDeltaY = (absDeltaX / absDeltaY) * 45.0;
				absDeltaX = absDeltaY * 2.0;
				
				if (absDeltaX < 0.0)
			}
		}
	} */
	
	s32 rng_a = 0x5d588b65;
	s32 rng_b = 0x1;
	s32 rand()
	{
		do {
			RNG_SEED = RNG_SEED * rng_a + rng_b;
		} while (0x7fff < RNG_SEED / 0x1ffff);
		
		return RNG_SEED / 0x1ffff;
	}
	
	// By Seeky, ported by JohnP55
	s32 _rand(s32 maxValue)
	{
		s32 divisor = 0xffffffff / (maxValue + 1);
		if (divisor < 1) divisor = 1;
		
		s32 res = maxValue + 1;
		
		while (res >= maxValue + 1)
		{
			RNG_SEED = RNG_SEED * rng_a + rng_b;
			res = RNG_SEED / divisor;
		}
		return res;
	}
	
	// By Seeky, ported by JohnP55
	s32 irand(s32 maxValue)
	{
		maxValue = i_abs(maxValue);
		
		if (maxValue == 0) return 0;
		else if (maxValue == 1) return _rand(1000) > 500;
		else if (maxValue == 100) return _rand(1009) / 10;
		else return _rand(maxValue);
	}
	
	f32 frand(f32 maxValue)
	{
		do {
			RNG_SEED = RNG_SEED * rng_a + rng_b;
		} while (0x7fff < RNG_SEED / 0x1ffff);

		return maxValue * (RNG_SEED / 0x1ffff) / 32767.0;
	}
}