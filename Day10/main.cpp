#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int valid_combinations(int sublist_length) {
    int valid{1};

    switch (sublist_length) {
        case 2:
            break;
        case 3:
            valid += 1;
            break;
        case 4:
            valid += 3;
            break;
        case 5:
            valid += 6;
            break;
    }
    return valid;
}

int main() {
    std::ifstream input{"E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day10\\input.txt"};
    int num;
    std::vector<int> adapters{};

    std::string line;
    while (input) {
        std::getline(input, line);
        if (line.empty()) {
            break;
        }
        num = std::stoi(line);
        adapters.push_back(num);
    }

    adapters.push_back(0);
    std::sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters.back() + 3);

    int difference_before;
    int difference_after;
    int differences[] = {0,0,0};

    std::vector<int> unskippables{};
    unskippables.push_back(0);
    for (int i=1; i < adapters.size()-1; i++) {
        difference_before = adapters[i] - adapters[i-1];
        ++differences[difference_before - 1];
        difference_after = adapters[i+1] - adapters[i];

        if (difference_before == 3 || difference_after == 3) {
            unskippables.push_back(i);
        } else if (difference_before == 2 && difference_after == 2) {
            unskippables.push_back(i);
        }
    }
    ++differences[2];
    unskippables.push_back(adapters.size()-1);

    unsigned long answer_2{1};
    for (int i=0; i<unskippables.size()-1; i++) {
        int a = unskippables[i];
        int b = unskippables[i+1];
        int sublist_length = b-a+1;
        answer_2 *= valid_combinations(sublist_length);
    }

    std::cout << "Answer 1: " << differences[0] * differences[2] << "\n";
    std::cout << "Answer 2: " << answer_2 << "\n";

    return 0;
}