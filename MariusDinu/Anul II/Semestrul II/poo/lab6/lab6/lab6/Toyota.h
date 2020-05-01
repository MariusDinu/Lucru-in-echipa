#pragma once

#include "Car.h"
#include "Weather.h"

class Toyota : public Car
{
public:
	Toyota();
	Toyota(int fuelAmount);

	bool doRace(Weather currentWeather, int circuitLength) override;

	double getRaceTime() override;

	std::string carType() override;
};