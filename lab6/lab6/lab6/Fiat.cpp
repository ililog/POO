#include "Fiat.h"

double Fiat::GetFuelCapacity() const {
	return 8.0;
}
double Fiat::GetFuelConsumption() const {
	return 0.8;
}
double Fiat::GetAverageSpeed(Weather weather) const {
	if (weather == Weather::Snow) {
		return 50.0;
	}
	else if (weather == Weather::Rain) {
		return 80.0;
	}
	else if (weather == Weather::Sunny) {
		return 100.0;
	}
	return 0.0;
}
const char* Fiat::GetName() const {
	return "Fiat";
}