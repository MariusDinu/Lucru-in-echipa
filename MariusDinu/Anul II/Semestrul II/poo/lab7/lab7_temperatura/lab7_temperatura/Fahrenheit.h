#pragma once
#include <stdlib.h>

int operator"" _Fahrenheit(const char* value)
{
	float temperature = atof(value);
	return (temperature - 32.f) / 1.8f;
}