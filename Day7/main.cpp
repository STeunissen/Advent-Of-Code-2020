#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

using bag_pair = std::pair<std::string, int>;

struct Bag {

    static std::unordered_map<std::string, Bag*> bag_index;

    std::vector<bag_pair> required_list;
    std::vector<std::string> contained_inside;

    std::string name;

    Bag(std::string new_name) : name{new_name} {}

    void requires_bags(std::string name, int amount) {
        bag_pair bags(name, amount);
        required_list.push_back(bags);
    }

    void add_container(std::string name) {
        contained_inside.push_back(name);
    }
};
std::unordered_map<std::string, Bag*> Bag::bag_index = {};

//Recursive solvers
void check_uniques(std::vector<std::string> container_list, std::unordered_map<std::string, int> &unique_list) {
    for (auto bag_name : container_list) {
        ++unique_list[bag_name];
        auto new_list = Bag::bag_index[bag_name]->contained_inside;
        check_uniques(new_list, unique_list);
    }
}
int check_nesting(std::vector<bag_pair> bag_list) {
    int local_sum{0};
    for (auto b : bag_list) {
        local_sum += b.second; //Add the bag itself
        auto new_list = Bag::bag_index[b.first]->required_list;
        local_sum += b.second * check_nesting(new_list);
    }
    return local_sum;
}


int check_nesting_verbose(std::vector<bag_pair> bag_list, int depth) {
    int local_sum{0};
    for (auto b : bag_list) {
        local_sum += b.second; //Add the bag itself
        auto new_list = Bag::bag_index[b.first]->required_list;
        for (int i=0; i<depth; ++i) {std::cout<<"|\t";}
        std::cout << "|" << b.second << "x " << b.first << " " << check_nesting(new_list) << "\n";
        local_sum += b.second * check_nesting_verbose(new_list, depth+1);

    }
    return local_sum;
}




int main() {

    std::ifstream input{"E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day7\\input.txt"};
    if (!input) {
        std::cout << "Could not open input file 'input_7.txt'!";
        return 1;
    }

    std::string line;
    while (input) {
        std::getline(input, line);
        std::stringstream parser{};
        parser << line;

        if (input.fail()) {
            break;
        }

        std::string current_bag_name, new_bag_pattern, new_bag_color;
        parser >> new_bag_pattern;
        parser >> new_bag_color;
        current_bag_name = new_bag_pattern + " " + new_bag_color;
        parser.ignore(13);

        Bag *current_bag;
        if (Bag::bag_index.find(current_bag_name) == Bag::bag_index.end()) {
            current_bag = new Bag(current_bag_name);
            Bag::bag_index[current_bag_name] = current_bag;
        } else {
            current_bag = Bag::bag_index[current_bag_name];
        }

        int amount;
        parser >> amount;
        if (parser.fail()) {
            parser.clear();
            continue;
        }

        while (parser) {
            parser >> new_bag_pattern;
            parser >> new_bag_color;
            std::string new_bag_name = new_bag_pattern + " " + new_bag_color;
            parser.ignore(6);

            current_bag->requires_bags(new_bag_name, amount);
            if (Bag::bag_index.find(new_bag_name) == Bag::bag_index.end()) {
                Bag *new_bag = new Bag(new_bag_name);
                Bag::bag_index[new_bag_name] = new_bag;
            }
            Bag::bag_index[new_bag_name]->add_container(current_bag_name);

            parser >> amount;
            if (parser.fail()) {
                parser.clear();
                break;
            } else {
            }
        }
    }

    std::cout << "Amount of registered bags: " << Bag::bag_index.size() << "\n";

    std::unordered_map<std::string, int> unique_containers{};
    auto direct_containers = Bag::bag_index["shiny gold"]->contained_inside;
    auto direct_required = Bag::bag_index["shiny gold"]->required_list;
    check_uniques(direct_containers, unique_containers);

    std::cout << "Answer 1: " << unique_containers.size() << "\n";
    std::cout << "Answer 2: " << check_nesting(direct_required) << "\n";

    return 0;
}