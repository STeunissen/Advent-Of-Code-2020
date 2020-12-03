#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

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

void parseData(std::vector<std::string> data){
    char letter = ' ';
    std::string password;
    std::string trash;
    int counter = 0;
    for (auto & i : data) {
        std::istringstream iss(i);
        int min, max;
        iss >> min >> max >> letter >> trash >> password;
        int amount = std::count(password.begin(), password.end(), letter);
        if(amount >= min && amount <= abs(max)) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}

void parseData2(std::vector<std::string> data){
    char letter = ' ';
    std::string password;
    std::string trash;
    int counter = 0;

    for (int i = 0; i < data.size(); ++i) {
        std::istringstream iss(data[i]);
        int first, second;
        char char_array[32];
        iss >> first >> second >> letter >> trash >> password;
        strncpy(char_array, password.c_str(), sizeof(char_array));
        std::cout << first << " " << abs(second)  << " " << letter  << " " << password  << " " << std::endl;
        second = abs(second);
        if ((char_array[first - 1] == letter) ^ (char_array[second - 1] == letter)){
            std::cout << "good" << std::endl;
            counter++;
        }
    }
    std::cout << counter << std::endl;
}

int main() {
    parseData(readFile("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day2\\input.txt"));
    parseData2(readFile("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day2\\input.txt"));
    return 0;
}
