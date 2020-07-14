#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <int> vec_one;
    vector <int> vec_two;
    vec_one.push_back(10);
    vec_one.push_back(20);
    cout << vec_one.at(0) << "\n" << vec_one.at(1) << "\n" << vec_one.size() <<  endl;
    vec_two.push_back(100);
    vec_two.push_back(200);
    cout << vec_two.at(0) << "\n" << vec_two.at(1) << "\n" << vec_two.size() <<  endl;
    vector <vector<int>> vec_two_d;
    vec_two_d.push_back(vec_one);
    vec_two_d.push_back(vec_two);
    cout << vec_two_d.size() << endl;
    cout << vec_two_d[0][0] << ", " <<  vec_two_d[0][1] << "\n" << vec_two_d[1][0] << ", " << vec_two_d[1][1] << endl;
    // vector method of indexing two d vectors below
//    cout << vec_two_d.at(0).at(0) << endl;
    // cannot index two d vectors with just one index
    vec_one.at(0) = 1000;
    cout << vec_two_d[0][0] << ", " <<  vec_two_d[0][1] << "\n" << vec_two_d[1][0] << ", " << vec_two_d[1][1] << endl;
    cout << vec_one.at(0) << "\n" << vec_one.at(1) << "\n" << vec_one.size() <<  endl;
    return 0;
}