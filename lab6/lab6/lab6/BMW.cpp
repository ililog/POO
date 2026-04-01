#include "BMW.h"

double BMW::GetFuelCapacity() const {
	return 20.0;
}
double BMW::GetFuelConsumption() const {
	return 1.5;
}
double BMW::GetAverageSpeed(Weather weather) const {
	if (weather == Weather::Snow) {
		return 70.0;
	}
	else if (weather == Weather::Rain) {
		return 100.0;
	}
	else if (weather == Weather::Sunny) {
		return 130.0;
	}
	return 0.0;
}
const char* BMW::GetName() const {
	return "BMW";
}