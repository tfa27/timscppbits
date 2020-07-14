#include <string>
#include <iomanip>
#include "Students.h"

int main(){
    std::ifstream i_file {"scores.txt", std::ios::in};
    Students students {i_file};
    students.display_scores();
	return 0;
}