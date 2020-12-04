#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readFile(const std::string& filename, std::ostream& output= std::cout){
    std::ifstream file (filename);
    std::vector<std::string> lines;

    if (!file.is_open()){
        std::cout << "wrong";
        return lines;
    }
    std::string line, temp;
    while(std::getline(file, line)){
        if (!line.empty()){
            temp +=  " " +  line;
        } else {
            lines.push_back(temp);
            temp = "";
        }
    }
    return lines;
}

//part 1
void countPassports(std::vector<std::string> data){
    int counter = 0;
    for (auto & i : data) {
        if (i.find("byr") != std::string::npos && i.find("iyr") != std::string::npos && i.find("eyr") != std::string::npos && i.find("hgt") != std::string::npos &&
                i.find("hcl") != std::string::npos && i.find("pid") != std::string::npos && i.find("ecl") != std::string::npos){
            counter++;
        }
    }
    std::cout << counter;
}


int main() {
    std::vector<std::string> data = readFile("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day4\\input.txt");
//    for (int i = 0; i < data.size();++i) {
//        std::cout << "On index postion: "<< i << " Passport: " << data[i] << std::endl;
//    }
    countPassports(data);
    return 0;
}
