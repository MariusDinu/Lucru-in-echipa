#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
private:
	int circuitLength;
	Weather currentWeather;
	int static const MAX_AMOUNT_OF_COMPETITORS = 16;
	Car* competingCars[MAX_AMOUNT_OF_COMPETITORS];
	int currentCompetingCarsAmount, currentFinishedCarsAmount, currentDnfCarsAmount;
	Car* finishedCars[MAX_AMOUNT_OF_COMPETITORS];
	Car* dnfCars[MAX_AMOUNT_OF_COMPETITORS];

	void rankingsByTime();

public:
	Circuit();

	void SetLength(int length);
	void SetWeather(Weather);
	void AddCar(Car* newCar);

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidntFinish();


};
