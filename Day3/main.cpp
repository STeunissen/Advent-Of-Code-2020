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
    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }
    return lines;
}

int calcTrees(int x_o, int y_o, std::vector<std::string> map){
    int x = 0;
    int trees = 0;
    int width = map.at(0).length();
    for (int y = 0; y < map.size(); y+=y_o){
        if(map.at(y).at(x) == '#')
            trees++;
        x = (x+x_o)%width;
    }
    return trees;
}

int main(){

    std::vector<std::string> map = readFile("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day3\\input.txt");
    long long total = calcTrees(1,1,map);
    int first = calcTrees(3,1,map);
    total *= first;
    total *= calcTrees(5,1,map);
    total *= calcTrees(7,1,map);
    total *= calcTrees(1,2,map);
    std::cout << "For exercise 1: " << first << "\nAnd for exercise 2: " << total  << std::endl;
}