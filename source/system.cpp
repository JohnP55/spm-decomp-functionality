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

	float angleABTbl[] = {
    1.0f, 1.273187f, 1.27303f, 1.272768f, 1.272402f, 1.271932f, 1.271358f,
    1.270681f, 1.269902f, 1.269021f, 1.268038f, 1.266956f, 1.265774f, 1.2644939f,
    1.263116f, 1.2616431f, 1.260075f, 1.258413f, 1.256659f, 1.254815f, 1.2528811f,
    1.250859f, 1.248752f, 1.24656f, 1.244285f, 1.2419291f, 1.239494f, 1.236981f,
    1.234393f, 1.2317311f, 1.228997f, 1.226192f, 1.22332f, 1.220382f, 1.217379f,
    1.2143151f, 1.211189f, 1.208006f, 1.204766f, 1.201471f, 1.1981241f, 1.1947269f,
    1.191281f, 1.1877871f, 1.18425f, 1.180669f, 1.177047f, 1.173386f, 1.169687f,
    1.165952f, 1.162184f, 1.158384f, 1.1545531f, 1.1506931f, 1.146806f, 1.142893f,
    1.138957f, 1.134998f, 1.131018f, 1.127019f, 1.1230021f, 1.118969f, 1.11492f,
    1.110858f, 1.106783f, 1.102697f, 1.098601f, 1.094496f, 1.090384f, 1.086266f,
    1.082142f, 1.078014f, 1.0738831f, 1.06975f, 1.065616f, 1.061482f, 1.057348f,
    1.053216f, 1.049087f, 1.04496f, 1.040838f, 1.036721f, 1.0326101f, 1.028504f,
    1.024406f, 1.020316f, 1.016234f, 1.0121599f, 1.0080971f, 1.004043f, 1.0f };

	// this function sucks to recode because anything can screw it over
	float angleABf(float x1, float y1, float x2, float y2)
	{
		float deltaX = x2 - x1;
		float deltaY = y2 - y1;
		
		float absDeltaX = f_abs(deltaX);
		float absDeltaY = f_abs(deltaY);
		
		float angle;
		s32 angleIndex;
		
		if (absDeltaX <= absDeltaY) {
			angle = 0.0f;
			if (absDeltaY != 0.0f) {
				absDeltaY = (absDeltaX / absDeltaY) * 45.0f;
				absDeltaX = absDeltaY * 2.0f;
				if (absDeltaX < 0.0f)
					angleIndex = -(int)(0.5f - absDeltaX);
				else
					angleIndex = (int)(absDeltaX + 0.5f);

				angle = absDeltaY * angleABTbl[angleIndex];

				if (deltaY < 0.0f) {
					if (deltaX < 0.0f)
						angle = 360.0f - angle;
				}

				else if (deltaX < 0.0f)
					angle = angle + 180.0f;
				else
					angle = 180.0f - angle;
			}
		}
		else {
			absDeltaY = (absDeltaY / absDeltaX) * 45.0f;
    		absDeltaX = absDeltaY * 2.0f;
    		if (absDeltaX < 0.0f) {
      			angleIndex = -(int)(0.5f - absDeltaX);
    		}
    		else {
      			angleIndex = (int)(absDeltaX + 0.5f);
    		}
    		angle = absDeltaY * angleABTbl[angleIndex];
    		if (deltaX < 0.0f && deltaY < 0.0f)
        		angle += 270.0f;
      		else if (deltaX < 0.0f)
        		angle = 270.0f - angle;
    		else if (deltaY < 0.0f)
      			angle = 90.0f - angle;
    		else
      			angle = angle + 90.0f;
  		}
  		return angle;
	}
	
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