#pragma once
class Movie {

private:
	char name[257];
	int release_year;
	double IMDB_score;
	int length_minutes;

public:
	void init();

	const char* get_name();
	void set_name(const char* movie_name);

	int get_release_year();
	void set_year(int year);

	double get_score();
	void set_score(double score);

	int get_length();
	void set_length(int length);

	int get_passed_years();
};