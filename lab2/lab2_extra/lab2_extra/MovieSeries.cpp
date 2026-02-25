#include "MovieSeries.h"
#include<algorithm>
#include<iostream>

bool condition_passed_years(Movie* M1, Movie* M2);

void MovieSeries::init() {
	count = 0;
}
void MovieSeries::add(Movie* film) {
	series[count] = film;
	count++;
}
void MovieSeries::print() {
	for (int i = 0; i < count; i++) {
		std::cout << "Name: " << series[i]->get_name() << '\n';
		std::cout << "IMDB score: " << series[i]->get_score() << '\n';
		std::cout << "Release year: " << series[i]->get_release_year() << '\n';
		std::cout << "Length: " << series[i]->get_length() << '\n';
		std::cout << "Passed years: " << series[i]->get_passed_years() << '\n';
		std::cout << '\n';
	}
}

void MovieSeries::sort() {
	std::sort(series, series + count, condition_passed_years);
}

bool condition_passed_years(Movie* M1, Movie* M2) {
	int passed_years1 = M1->get_passed_years();
	int passed_years2 = M2->get_passed_years();
	if (passed_years1 > passed_years2) return 1;
	return 0;
}