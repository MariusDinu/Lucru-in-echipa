#pragma once

#include "Car.h"
#include "Weather.h"

class Mazda : public Car
{
public:
	Mazda();
	Mazda(int fuelAmount);

	bool doRace(Weather currentWeather, int circuitLength) override;

	double getRaceTime() override;

	std::string carType() override;
};