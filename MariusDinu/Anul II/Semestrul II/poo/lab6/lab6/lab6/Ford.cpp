#include "Ford.h"

Ford::Ford() : Car()
{
	fuelCapacity = 415;
	fuelConsumption = 4;
	averageSpeed = 70;
}

Ford::Ford(int fuelAmount) : Car()
{
	if (fuelAmount <= 415 && fuelAmount > 0)
		fuelCapacity = fuelAmount;
	else
		fuelCapacity = 415;
	fuelConsumption = 4;
	averageSpeed = 70;
}

bool Ford::doRace(Weather currentWeather, int circuitLength)
{
	if (fuelCapacity / fuelConsumption < circuitLength) {
		lastRaceTime = -1; //Did not finish the race
		return false;
	}
	else {
		if (currentWeather == Weather::Snow) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.2;
		}
		else if (currentWeather == Weather::Rain) {
			lastRaceTime = (circuitLength / averageSpeed) * 0.9;
		}
		else
		{
			lastRaceTime = (circuitLength / averageSpeed) * 1.0;
		}
	}
	return true;
}

double Ford::getRaceTime()
{
	return lastRaceTime;
}

std::string Ford::carType()
{
	return "Ford";
}