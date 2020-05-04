#pragma once

#include "Car.h"
#include "Weather.h"

class Dacia : public Car
{

public:
	Dacia();

	Dacia(int fuelAmount);

	bool doRace(Weather currentWeather, int circuitLength) override;

	double getRaceTime() override;

	std::string carType() override;
};
