#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::ifstream file("E:\\\\Saxion\\\\Technische Informatica\\\\Datastructures\\\\Advent-Of-Code-2020\\\\Day6\\\\input.txt");
    std::string an, currAn;
    int sum1 = 0, sum2 = 0, people = 0;

    while(getline(file, currAn)){
        if(currAn.length() != 0 && file.peek() != EOF){
            an += currAn;   //Adding together all the answers in a group
            people++;       //Number of people in the group, will be needed for part 2 later
        }
        else{
            if(file.peek() == EOF){ //I have this beacause I can't figure out another way to enter the else before the end of the file
                an += currAn;
                people++;
            }
            //Part 1 and preparation for part 2
            sort(an.begin(), an.end());                                                         //Sorting the group's answers so I can apply unique on it
            std::string sortedAn = an;                                                          //Saving the sorted answers for later since uniqe messes up the string
            std::string uniqAn = std::string( an.begin(), unique(an.begin(), an.end()) );       //Getting the uniqes and saving them to use them comfortably later
            sum1 += uniqAn.length();                                                            //The sum of unique characters are the first part's solution so I'm adding them together

            for(char & i : uniqAn)                                            //Part 2
                if(std::count(sortedAn.begin(), sortedAn.end(), i) == people) sum2++;   //Getting the count of every given answer and comparig it to the number of people in that specific group
            //If everyone answered to that question then the count will be equal to the amount of people, and the sum goes up
            an.clear();
            people = 0;
        }
    }
    std::cout << sum1 << '\n' << sum2 << '\n';

    return 0;
}