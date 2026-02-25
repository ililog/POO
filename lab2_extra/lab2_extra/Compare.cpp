#include "Compare.h"
#include<cstring>

int movie_compare_name(Movie& M1, Movie& M2) {
	int rez = strcmp(M1.get_name(), M2.get_name());
	if (rez == 0) return 0;
	if (rez < 0) return -1;
	return 1;
}
int movie_compare_year(Movie& M1, Movie& M2) {
	int year1 = M1.get_release_year();
	int year2 = M2.get_release_year();
	if (year1 == year2) return 0;
	if (year1 < year2) return -1;
	return 1;
}
int movie_compare_score(Movie& M1, Movie& M2) {
	double score1 = M1.get_score();
	double score2 = M2.get_score();
	if (score1 == score2) return 0;
	if (score1 < score2) return -1;
	return 1;
}
int movie_compare_length(Movie& M1, Movie& M2) {
	int length1 = M1.get_length();
	int length2 = M2.get_length();
	if (length1 == length2) return 0;
	if (length1 < length2) return -1;
	return 1;
}
int movie_compare_passed_years(Movie& M1, Movie& M2) {
	int passed_years1 = M1.get_passed_years();
	int passed_years2 = M2.get_passed_years();
	if (passed_years1 == passed_years2) return 0;
	if (passed_years1 < passed_years2) return -1;
	return 1;
}