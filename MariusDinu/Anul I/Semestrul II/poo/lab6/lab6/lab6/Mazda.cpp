#include "Mazda.h"

Mazda::Mazda() : Car()
{
	fuelCapacity = 800;
	fuelConsumption = 4;
	averageSpeed = 55;
}

Mazda::Mazda(int fuelAmount) : Car()
{
	if (fuelAmount <= 800 && fuelAmount > 0)
		fuelCapacity = fuelAmount;
	else
		fuelCapacity = 800;
	fuelConsumption = 4;
	averageSpeed = 55;
}

bool Mazda::doRace(Weather currentWeather, int circuitLength)
{
	if (fuelCapacity / fuelConsumption < circuitLength) {
		lastRaceTime = -1; //Did not finish the race
		return false;
	}
	else {
		if (currentWeather == Weather::Snow) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.3;
		}
		else if (currentWeather == Weather::Rain) {
			lastRaceTime = (circuitLength / averageSpeed) * 0.9;
		}
		else
		{
			lastRaceTime = (circuitLength / averageSpeed) * 0.8;
		}
	}
	return true;
}

double Mazda::getRaceTime()
{
	return lastRaceTime;
}

std::string Mazda::carType()
{
	return "Mazda";
}