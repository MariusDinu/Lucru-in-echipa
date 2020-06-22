#pragma once

#include "Car.h"
#include "Weather.h"

class Ford : public Car
{
public:
	Ford();
	Ford(int fuelAmount);

	bool doRace(Weather currentWeather, int circuitLength) override;

	double getRaceTime() override;

	std::string carType() override;
};
