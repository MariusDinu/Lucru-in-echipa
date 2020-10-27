#include "Toyota.h"

Toyota::Toyota() : Car()
{
	fuelCapacity = 600;
	fuelConsumption = 2;
	averageSpeed = 55;
}

Toyota::Toyota(int fuelAmount) : Car()
{
	if (fuelAmount <= 600 && fuelAmount > 0)
		fuelCapacity = fuelAmount;
	else
		fuelCapacity = 600;
	fuelConsumption = 2;
	averageSpeed = 55;
}

bool Toyota::doRace(Weather currentWeather, int circuitLength)
{
	if (fuelCapacity / fuelConsumption < circuitLength) {
		lastRaceTime = -1; //Did not finish the race
		fuelCapacity = 0;
		return false;
	}
	else {
		if (currentWeather == Weather::Snow) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.2;
		}
		else if (currentWeather == Weather::Rain) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.0;
		}
		else
		{
			lastRaceTime = (circuitLength / averageSpeed) * 1.1;
		}
		fuelCapacity = fuelCapacity - circuitLength * fuelConsumption;
	}
	return true;
}

double Toyota::getRaceTime()
{
	return lastRaceTime;
}

std::string Toyota::carType()
{
	return "Toyota";
}