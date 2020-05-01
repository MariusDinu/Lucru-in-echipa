#include "Circuit.h"
#include <stdio.h>
#include <iostream>

void Circuit::rankingsByTime()
{
	for (int i = 0; i < currentFinishedCarsAmount - 1; i++) {
		for (int j = i + 1; j < currentFinishedCarsAmount; j++) {
			if (finishedCars[i]->getRaceTime() > finishedCars[j]->getRaceTime())
			{
				Car* tempCar = finishedCars[i];
				finishedCars[i] = finishedCars[j];
				finishedCars[j] = tempCar;
			}
		}
	}
}

Circuit::Circuit()
{
	currentCompetingCarsAmount = currentDnfCarsAmount = currentFinishedCarsAmount = 0;
	this->circuitLength = 265;
	this->currentWeather = Weather::Sunny;
}

void Circuit::SetLength(int length)
{
	this->circuitLength = length;
}

void Circuit::SetWeather(Weather newWeather)
{
	this->currentWeather = newWeather;
}

void Circuit::AddCar(Car* newCar)
{
	if (currentCompetingCarsAmount < MAX_AMOUNT_OF_COMPETITORS) {
		competingCars[currentCompetingCarsAmount++] = newCar;
	}
}

void Circuit::Race()
{
	for (int i = 0; i < currentCompetingCarsAmount; i++) {
		if (competingCars[i]->doRace(currentWeather, circuitLength)) {
			finishedCars[currentFinishedCarsAmount++] = competingCars[i];
		}
		else
		{
			dnfCars[currentDnfCarsAmount++] = competingCars[i];
		}
	}

	rankingsByTime();
}

void Circuit::ShowFinalRanks()
{
	std::cout << "Cars who finished: \n";
	for (int i = 0; i < currentFinishedCarsAmount; i++) {
		std::cout << i + 1 << " - " << finishedCars[i]->carType() << " : Finished in - " << finishedCars[i]->getRaceTime() << "\n";
	}
}

void Circuit::ShowWhoDidntFinish()
{
	std::cout << "Cars who did not finish: \n";
	for (int i = 0; i < currentDnfCarsAmount; i++) {
		std::cout << dnfCars[i]->carType() << "\n";
	}
}