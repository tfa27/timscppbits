#ifndef _STUDENTS_H_
#define _STUDENTS_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Student.h"

class Students{
public:
    std::string correct_answers {};
    std::vector<Student *> s_vec;

    Students(std::ifstream &i_file) {
        if(!i_file.is_open()){
            std::cout << "Problem opening file.\n";
        }
        i_file >> correct_answers;
        while (!i_file.eof()){
            std::string n {};
            i_file >> n;
            std::string a {};
            i_file >> a;
            s_vec.push_back(new Student{n, a, correct_answers});
        }
    }

    
    void add_student(std::string name, std::string their_answers){
        s_vec.push_back(new Student{name, their_answers, correct_answers});
    }
    
    void display_scores(){
        int student_count {0};
        int scores {0};
        std::cout << std::right <<std:: setw(20) << "Student name" << std::right << std::setw(20) << "Scores" << std::endl;
        std::cout << std::setw(41) << std::right<< std::setfill('-') << " " << std::endl;
        std::setfill(' ');
        for (auto v : s_vec){
            v->display_student();
            student_count += 1;
            scores += v->score;
        }
        double average_score {static_cast<double>(scores) / student_count};
        std::cout << std::setw(41) << std::right<< std::setfill('-') << " " << std::endl;
        std::cout << std::setfill(' ') << std::setw(20) << std::right << "Average score" << std::setw(20) << std::right << average_score << std::endl;
    }
};

#endif // _STUDENTS_H_