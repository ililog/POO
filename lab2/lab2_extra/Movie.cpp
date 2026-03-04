using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "Movie.h"

void Movie::init() {
	name[0] = 0;
	release_year = 0;
	IMDB_score = 0;
	length_minutes = 0;
}

const char* Movie::get_name() {
	return name;
}

void Movie::set_name(const char* movie_name) {
	strncpy(name, movie_name, 256);
	name[256] = 0;
}

int Movie::get_release_year() {
	return release_year;
}
void Movie::set_year(int year) {
	release_year = year;
}

double Movie::get_score() {
	return IMDB_score;
}
void Movie::set_score(double score) {
	IMDB_score = score;
}

int Movie::get_length() {
	return length_minutes;
}

void Movie::set_length(int length) {
	length_minutes = length;
}

int Movie::get_passed_years() {
	return 2026 - release_year;
}