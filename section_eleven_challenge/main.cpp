#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

void display_menu_options();
void initial_data_entry(vector<int> &data);
void quit_main(bool &done);
void display_data(const vector<int> &data);
void add_element(vector <int> &data);
void calc_mean(const vector <int> &data);
void smallest_num(const vector <int> &data);
void largest_num(const vector <int> &data);
void main_func(vector <int> &data);
void find_element(const vector <int> &data, const int target);
char get_selection();

//const vector <char> options {'p', 'a', 'm', 's', 'l', 'q'};

int main(){
    // menu driven system like section nine
    // create functions for each action
    vector <int> data {};
    main_func(data);
	return 0;
}

void display_menu_options(){
    cout << "\n\nPlease select from the following options...\nP - print list\nF - find element in list\nA - add an element to list\nM - display mean of list\nS - display smallest value\nL - display largest value\nQ - quit program\nEnter option: ";
}

void initial_data_entry(vector<int> &data){
    int data_length {};
    cout << "Please enter the amount of data points: ";
    cin >> data_length;
    if (data_length > 0){
        for (int i {0}; i < data_length; i++){
            int this_el {};
            cout << "Please enter data value at element " << i + 1 << ": ";
            cin >> this_el;
            data.push_back(this_el);
        }
    }
}

void quit_main(bool &done){
    done = 1;
    cout << "Goodbye.\n";
}

void display_data(const vector<int> &data){
    if (data.size() < 1){
        cout << "[] - the list is empty.\n";
    } else{
        cout << "[ ";
        for (auto element : data){
            cout << element << " ";
        }
        cout << "]\n";
    }
}

void add_element(vector <int> &data){
    cout << "Enter new element to add to end of list: ";
    int new_element {};
    cin >> new_element;
    data.push_back(new_element);
    cout << new_element << " added.\n";
}

void calc_mean(const vector <int> &data){
    if (data.size() == 0){
        cout << "Unable to calculate mean - list is empty.\n";
    } else {
        int addition {0};
        for (auto el : data){
            addition += el;
        }
        double mean {static_cast<double>(addition) / data.size()};
        cout << "Mean: " << mean << "\n";
    }
}

void smallest_num(const vector <int> &data){
    if (data.size() == 0){
        cout << "Unable to find smallest number - list is empty.\n";
    } else {
        int small_num {data.at(0)};
        for (auto num : data){
            if (num < small_num){
                small_num = num;
            }
        }
        cout << "The smallest number is " << small_num << "\n";
    }
}

void largest_num(const vector <int> &data){
    if (data.size() == 0){
        cout << "Unable to find largest number - list is empty.\n";
    } else {
        int large_num {data.at(0)};
        for (auto large : data){
            if (large > large_num){
                large_num = large;
            }
        }
        cout << "The largest number is " << large_num << "\n";
    }
}

char get_selection(){
    char inp_selection {};
    display_menu_options();
    cin >> inp_selection;
    inp_selection = tolower(inp_selection);
    cout << "\n";
    return inp_selection;
}

void find_element(const vector <int> &data){
    bool found {0};
    int idx {0};
    int i{0};
    int target {};
    cout << "Enter target integer to find: ";
    cin >> target;
    cout << "\n";
    do {
        if (data.at(i) == target){
            found = 1;
            idx = i;
            i = data.size();
        }
        i += 1;
    } while (i < data.size());
    if (found == 1){
        cout << "Target " << target << " lies at index " << idx << " in data.\n";
    } else {
        cout << "Target " << target << " does not exist in data set.\n";
    }
}

void main_func(vector <int> &data){
    cout << "Welcome to this simple data manipulation project!\n";
    initial_data_entry(data);
    bool done {0};
    do {
        char inp_selection {get_selection()};
        switch (inp_selection){
            case 'p': display_data(data); break;
            case 'a': add_element(data); break;
            case 'm': calc_mean(data); break;
            case 's': smallest_num(data); break;
            case 'l': largest_num(data); break;
            case 'f': find_element(data); break;
            case 'q': quit_main(done); break;
            default: cout << "Invalid selection.\n"; break;
        }
    } while (!done);
}

//void main_func(vector <int> &data){ // can be done more efficiently with switch case statement
//    cout << "Welcome to this simple data manipulation project!\n";
//    initial_data_entry(data);
//    bool done {0};
//    do {
//        char inp_selection {};
//        display_menu_options();
//        cin >> inp_selection;
//        inp_selection = tolower(inp_selection);
//        cout << "\n";
//        if (inp_selection == options.at(5)){
//            quit_main(done);
//        } else if (inp_selection == options.at(0)){
//            display_data(data);
//        } else if (inp_selection == options.at(1)){
//            add_element(data);
//        } else if (inp_selection == options.at(2)){
//            calc_mean(data);
//        } else if (inp_selection == options.at(3)){
//            smallest_num(data);
//        } else if (inp_selection == options.at(4)) {
//            largest_num(data);
//        } else {
//            cout << "Invalid selection.\n";
//        }
//    } while (!done);
//}