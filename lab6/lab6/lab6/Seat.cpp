#include "Seat.h"

double Seat::GetFuelCapacity() const {
	return 10.0;
}
double Seat::GetFuelConsumption() const {
	return 1.0;
}
double Seat::GetAverageSpeed(Weather weather) const {
	if (weather == Weather::Snow) {
		return 80.0;
	}
	else if (weather == Weather::Rain) {
		return 110.0;
	}
	else if (weather == Weather::Sunny) {
		return 140.0;
	}
	return 0.0;
}
const char* Seat::GetName() const {
	return "Seat";
}