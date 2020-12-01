#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> readFile(const std::string& filename, std::ostream& output= std::cout){
    std::ifstream file (filename);
    std::vector<std::string> lines;

    if (!file.is_open()){
        std::cout << "wrong";
        return lines;
    }
    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }
    return lines;
}

void checkNumbers(std::vector<std::string> numbers){
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = 0; j < numbers.size(); ++j) {
            if ((std::stoi(numbers[i]) + std::stoi(numbers[j])) == 2020){
                std::cout << numbers[i] + " + " + numbers[j] + " = " << std::stoi(numbers[i]) + std::stoi(numbers[j]) << std::endl;
            }
        }
    }
}

int main() {
    checkNumbers(readFile("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day1\\input.txt"));
    return 0;
}
