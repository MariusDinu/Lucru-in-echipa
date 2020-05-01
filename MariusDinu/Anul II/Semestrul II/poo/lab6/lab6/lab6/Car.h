#pragma once
#include <string>
#include "Weather.h"

class Car
{
protected:
	int fuelCapacity;
	int fuelConsumption;
	int averageSpeed;
	double lastRaceTime;
public:
	virtual double getRaceTime() = 0;
	virtual bool doRace(Weather currentWeather, int circuitLength) = 0;
	virtual std::string carType() = 0;
};