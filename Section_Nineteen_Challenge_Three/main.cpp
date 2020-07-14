#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::ifstream play_text {"romeo_and_juliet.txt", std::ios::in};
    
    if (!play_text){
        std::cerr << "Problem opening file.\n" << std::endl;
        return 1;
    }
    
    std::string search_word {};
    std::cout << "Enter word to count in Romeo and Juliet: ";
    std::cin >> search_word;
    
    int overall_count {0};
    std::string this_word {};
    int word_count {0};
    while (!play_text.eof()){
        play_text >> this_word;
        std::size_t found = this_word.find(search_word);
        if (found < 1000000){
            word_count += 1;
        }
        overall_count += 1;
    }
    std::cout << overall_count << " words were searched, " << search_word << " was found " << word_count << " times.\n";
    
	return 0;
}