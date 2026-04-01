#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const {
	return 30.0;
}
double RangeRover::GetFuelConsumption() const {
	return 2.0;
}
double RangeRover::GetAverageSpeed(Weather weather) const {
	if (weather == Weather::Snow) {
		return 80.0;
	}
	else if (weather == Weather::Rain) {
		return 120.0;
	}
	else if (weather == Weather::Sunny) {
		return 150.0;
	}
	return 0.0;
}
const char* RangeRover::GetName() const {
	return "RangeRover";
}