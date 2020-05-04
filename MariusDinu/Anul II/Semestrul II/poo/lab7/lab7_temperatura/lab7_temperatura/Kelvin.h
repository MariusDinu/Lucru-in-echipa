#pragma once
#include <stdlib.h>

int operator"" _Kelvin(const char* value)
{
	float temperature = atof(value);
	return temperature - 273.15f;
}