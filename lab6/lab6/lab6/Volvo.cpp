#include "Volvo.h"
#include "Weather.h"

double Volvo::GetFuelCapacity() const {
	return 10.0;
}
double Volvo::GetFuelConsumption() const {
	return 1.0;
}
double Volvo::GetAverageSpeed(Weather weather) const {
	if (weather == Weather::Snow) {
		return 60.0;
	}
	else if (weather == Weather::Rain) {
		return 90.0;
	}
	else if (weather == Weather::Sunny){
		return 120.0;
	}
	return 0.0;
}
const char* Volvo::GetName() const {
	return "Volvo";
}