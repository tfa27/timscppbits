#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Student{
public:
    std::string student_name {};
    int score {};
    
    Student(std::string name, std::string answers, std::string correct_answers) : student_name {name}, score {scoring(answers, correct_answers)} {}
    
    int scoring(std::string &answers, std::string &correct_answers) {
        int score_count {0};
        for (size_t i {0}; i < answers.length(); i++){
            if (answers[i] == correct_answers[i]){
                score_count += 1;
            }
        }
        return score_count;
    }
    void display_student(){
        std::cout << std::setfill(' ') << std::right <<std:: setw(20) << student_name << std::right << std::setw(18) << score << "/5" << std::endl;
    }
};

#endif //_STUDENT_H_