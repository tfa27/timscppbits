#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test () : data {0} {std::cout << "Test constructor: " << data << std::endl;}
    Test(int d) : data {d} {std::cout << "Test constructor: " << data << std::endl;}
    int get_data () const {return data;}
    ~Test() {std::cout << "Destructor called for " << data << std::endl;}
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main(){
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points? ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num){
    for (size_t i{0}; i < num; i++){
        std::cout << "Enter integer value for index " << i+1 << ": ";
        int temp_num{};
        std::cin >> temp_num;
        std::cout << "\n";
        vec.push_back(std::make_shared<Test>(temp_num));
    }
}

void display(const std::vector<std::shared_ptr<Test>>&vec){
    for(size_t i {0}; i < vec.size(); i++){
        std::cout << "Data at index " << i + 1 << ": " << (vec.at(i))->get_data() << std::endl;
    }
}