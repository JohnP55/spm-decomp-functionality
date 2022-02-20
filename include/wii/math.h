#pragma once

namespace math
{
	extern "C"
	{
		double pow(double x, double y);
		double sqrt(double x);
		
		double sin(double x);
		double cos(double x);
		double tan(double x);
		double acos(double x);
		double atan(double x);
		double atan2(double x);
		double fmod(double x, double y);
		double floor(double x);
	}
}