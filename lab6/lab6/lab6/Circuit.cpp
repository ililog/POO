#include "Circuit.h"
#include<iostream>
using namespace std;

Circuit::Circuit() : length(0), weather(Weather::Sunny), car_count(0), finished_car_count(0), not_finished_car_count(0) {}
Circuit::~Circuit() {
	for (int i = 0; i < car_count; i++) {
		delete cars[i]; //daca distrug doar cars distrug si celelalte obiecte
	}
}

void Circuit::SetLength(double L) {
	length = L;
}
void Circuit::SetWeather(Weather w) {
	weather = w;
}
void Circuit::AddCar(Car* car) {
	if (car_count < 100) {
		cars[car_count++] = car;
	}
}
void Circuit::Race() {
	finished_car_count = 0; not_finished_car_count = 0;
	for (int i = 0; i < car_count; i++) {
		Car* current_car = cars[i];
		double fuel_needed = (length / 100.0) * current_car->GetFuelConsumption();
		if (current_car->GetFuelCapacity() >= fuel_needed) {
			double speed = current_car->GetAverageSpeed(weather);
			double time = length / speed;
			finished_cars[finished_car_count] = current_car;
			finish_times[finished_car_count] = time;
			finished_car_count++;
		}
		else {
			not_finished_cars[not_finished_car_count++] = current_car;
		}
	}

	for (int i = 0; i < finished_car_count - 1; i++) {
		for (int j = i + 1; j < finished_car_count; j++) {
			if (finish_times[i] > finish_times[j]) {
				swap(finish_times[i], finish_times[j]);
				Car* tempcar = finished_cars[i];
				finished_cars[i] = finished_cars[j];
				finished_cars[j] = tempcar;
			}
		}
	}
}
void Circuit::ShowFinalRanks() {
	cout << "Final Ranks: \n";
	for (int i = 0; i < finished_car_count; i++) {
		cout << i + 1 << ". " << finished_cars[i]->GetName() << "   Time: " << finish_times[i] << " hours\n";
	}
	cout << '\n';
}
void Circuit::ShowWhoDidNotFinish() {
	if (not_finished_car_count == 0) {
		cout << "All cars finished!\n";
		return;
	}
	cout << "Did not finish: \n";
	for (int i = 0; i < not_finished_car_count; i++) {
		cout << not_finished_cars[i]->GetName() << '\n';
	}
	cout << '\n';
}