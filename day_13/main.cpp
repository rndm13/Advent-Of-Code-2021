#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

struct fold {
    char axis{};
    int value{};
};

std::istream& operator>>(std::istream& is,fold &f) {
    std::string s;
    std::cin >> s >> s;
    is >> f.axis;
    is.ignore(1,'=');
    is >> f.value; 
    return is;
}
std::istream& operator>>(std::istream& is,std::set<std::pair<int,int>> &set) {
    std::string s;
    is >> s;
    if (!s.empty())
        set.insert(std::make_pair(stoi(s.substr(0,s.find(','))),stoi(s.substr(s.find(',')+1,99))));
    return is;
}
std::set<std::pair<int,int>> process_fold(std::set<std::pair<int,int>> *point_set, fold input_fold) {
    std::set<std::pair<int,int>> new_point_set;
    for (auto [x,y] : *point_set) {
        if (input_fold.axis == 'x' && x > input_fold.value) 
            new_point_set.insert(std::make_pair(input_fold.value-(x-input_fold.value),y));
        else if (input_fold.axis == 'y' && y > input_fold.value)
            new_point_set.insert(std::make_pair(x,input_fold.value-(y-input_fold.value)));
        else if ((input_fold.axis == 'x' && x < input_fold.value)||(input_fold.axis == 'y' && y < input_fold.value))
            new_point_set.insert(std::make_pair(x,y));
    }
    return new_point_set;
}
int main() {
    std::set<std::pair<int,int>> point_set;
    std::ifstream fin("input.txt");
    while (fin >> point_set);
    fold input_fold;
    while (std::cin >> input_fold) 
        point_set = process_fold (&point_set, input_fold);
    for (int y = 0;y<7;y++) {
        for (int x = 0;x<40;x++) {
            if (point_set.find(std::make_pair(x,y))!=point_set.end())
                std::cout <<'#';
            else
                std::cout <<'.';
        }
        std::cout <<'\n';
    }
    return 0;
}
