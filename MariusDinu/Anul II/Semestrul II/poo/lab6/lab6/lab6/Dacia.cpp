#include "Dacia.h"

Dacia::Dacia() : Car()
{
	fuelCapacity = 200;
	fuelConsumption = 3;
	averageSpeed = 65;
}

Dacia::Dacia(int fuelAmount) : Car()
{
	if (fuelAmount <= 320 && fuelAmount > 0)
		fuelCapacity = fuelAmount;
	else
		fuelCapacity = 200;
	fuelConsumption = 3;
	averageSpeed = 65;
}

bool Dacia::doRace(Weather currentWeather, int circuitLength)
{
	if (fuelCapacity / fuelConsumption < circuitLength) {
		lastRaceTime = -1; //Did not finish the race
		return false;
	}
	else {
		if (currentWeather == Weather::Snow) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.0;
		}
		else if (currentWeather == Weather::Rain) {
			lastRaceTime = (circuitLength / averageSpeed) * 1.1;
		}
		else
		{
			lastRaceTime = (circuitLength / averageSpeed) * 0.9;
		}
	}
	return true;
}

double Dacia::getRaceTime()
{
	return lastRaceTime;
}

std::string Dacia::carType()
{
	return "Dacia";
}