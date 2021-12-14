#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
std::istream& operator>>(std::istream &is, std::unordered_map<std::string,std::unordered_set<std::string>> &input) {
    std::string s;
    is >> s;
    input[s.substr(0,s.find('-'))].insert(s.substr(s.find('-')+1,99));
    input[s.substr(s.find('-')+1,99)].insert(s.substr(0,s.find('-')));
    return is;
}
namespace brute_force {
long long dfs(std::unordered_map<std::string, std::unordered_set<std::string>> *paths, std::string point, bool secondtime=false, std::unordered_map<std::string,bool> flags = {}) {
    long long result = 0;
    if (point == "end")
        return 1;
    if (flags[point]) {
        if (secondtime || point == "start")
            return 0;
        else
            secondtime=true;
    }
    if (islower(point[0]))
        flags[point] = true;
    for (auto dest : (*paths)[point])
        result += dfs(paths, dest, secondtime, flags);
    return result;
}
}
/*
long long solve_p1(std::unordered_map<std::string, std::unordered_set<std::string>> *paths, std::string point,long long *end_value, long long value = 1, std::unordered_map<std::string,bool> flags = {}) {
    flags[point] = true;
    bool end=false;
    value*=std::pow(2,std::count_if((*paths)[point].begin(),(*paths)[point].end(),[](string s){return !flags[s];}));
    for (auto dest : (*paths)[point])
        if (dest == "end")
            end=true;
        
        value += dfs(paths, dest, secondtime, flags);
    if (end)
        (*end_value)+=value
    return ;
    
}
*/
int main() {
    std::unordered_map<std::string,std::unordered_set<std::string>> paths;
    while (std::cin >> paths);
    std::cout << brute_force::dfs(&paths,"start");
    return 0;
}
