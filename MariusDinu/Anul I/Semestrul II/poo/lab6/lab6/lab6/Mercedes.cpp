#include "Mercedes.h"

Mercedes::Mercedes() : Car()
{
	fuelCapacity = 750;
	fuelConsumption = 2;
	averageSpeed = 80;
}

Mercedes::Mercedes(int fuelAmount) : Car()
{
	if (fuelAmount <= 750 && fuelAmount > 0)
		fuelCapacity = fuelAmount;
	else
		fuelCapacity = 750;
	fuelConsumption = 2;
	averageSpeed = 80;
}

bool Mercedes::doRace(Weather currentWeather, int circuitLength)
{
	if (fuelCapacity / fuelConsumption < circuitLength) {
		lastRaceTime = -1; //Did not finish the race
		return false;
	}
	else {
		if (currentWeather == Weather::Snow) {
			lastRaceTime = (circuitLength / averageSpeed) * 0.8;
		}
		else if (currentWeather == Weather::Rain) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.0;
		}
		else
		{
			lastRaceTime = (circuitLength / averageSpeed) * 1.1;
		}
	}
	return true;
}

double Mercedes::getRaceTime()
{
	return lastRaceTime;
}

std::string Mercedes::carType()
{
	return "Mercedes";
}