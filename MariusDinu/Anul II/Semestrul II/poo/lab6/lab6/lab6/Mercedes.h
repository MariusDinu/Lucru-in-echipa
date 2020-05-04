#pragma once

#include "Car.h"
#include "Weather.h"

class Mercedes : public Car
{
public:
	Mercedes();
	Mercedes(int fuelAmount);

	bool doRace(Weather currentWeather, int circuitLength) override;

	double getRaceTime() override;

	std::string carType() override;
};