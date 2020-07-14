#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// basically the challenge is to get the romeo and juliet files and add line numbers

int main(){
	std::fstream i_file {"romeo_and_juliet.txt", std::ios::in};
    std::ofstream o_file{"output.txt", std::ios::out};
    
    if (!i_file){
        std::cerr << "Error opening file\n";
        return 1;
    }
    if (!o_file){
        std::cerr << "Error creating file\n";
        return 1;
    }
    
    int line_count {1};
    while (!i_file.eof()){
        std::string line {};
        std::getline(i_file, line);
        
        if (line == ""){
            o_file << std::endl;
        }else {
            o_file << std::setw(10) << std::left << line_count << " ";
            o_file << line << std::endl;
            line_count += 1;
        }
    }
    
    o_file.close();
    
    
    std::cout << "Copy complete\n";
    
	return 0;
}