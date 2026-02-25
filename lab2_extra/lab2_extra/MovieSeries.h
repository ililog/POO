#pragma once
#include "Movie.h"
class MovieSeries {

private:
	int count;
	Movie* series[16];

public:
	void init();
	void add(Movie* film);
	void print();
	void sort();
};