#include "spm/system.h"

#include <wii/types.h>

namespace spm::system
{
	double d_abs(double d)
	{
		return d < 0 ? d * -1 : d;
	}
	
	s32 i_abs(s32 i)
	{
		return i < 0 ? i * -1 : i;
	}
	
	double compAngle(double angle1, double angle2)
	{
		if (d_abs(angle2 - angle1) >= 180.0)
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
	
	double frand(double maxValue)
	{
		do {
			RNG_SEED = RNG_SEED * rng_a + rng_b;
		} while (0x7fff < RNG_SEED / 0x1ffff);

		return maxValue * (RNG_SEED / 0x1ffff) / 32767.0;
	}
}