#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
	double length;
	Weather weather;

	Car* cars[100];
	int car_count;

	Car* finished_cars[100];
	double finish_times[100];
	int finished_car_count;

	Car* not_finished_cars[100];
	int not_finished_car_count;
public: 
	Circuit();
	~Circuit();

	void SetLength(double L);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};