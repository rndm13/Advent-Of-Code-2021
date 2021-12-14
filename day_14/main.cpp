#include <iostream>
#include <algorithm>
#include <string>
#include <map>

std::istream& operator>>(std::istream &is, std::map<std::pair<char,char>,char> &m) {
    char a,b;
    is >> a >> b;
    is.ignore(4,'>');
    is >> m[std::make_pair(a,b)];
    return is;
}

std::map<std::pair<char,char>,unsigned long long> pair_insertion(
        std::map<std::pair<char,char>,char> *rules,
        std::map<std::pair<char,char>,unsigned long long> *polymer_template,
        std::map<char,unsigned long long> *character_count)
{
    std::map<std::pair<char,char>,unsigned long long> new_polymer_template{};
    for (auto [p, num] : *polymer_template) {
        if ((*rules)[p]!=0) {
            new_polymer_template[std::make_pair(p.first, (*rules)[p])]+=num;
            new_polymer_template[std::make_pair((*rules)[p], p.second)]+=num;
            (*character_count)[(*rules)[p]]+=num;
        }
        else
            new_polymer_template[p]+=num;
    }
    return new_polymer_template;
}
 
int main() {
    std::string polymer_template_input{};

    std::cin >> polymer_template_input;

    std::map<std::pair<char,char>,char> rules{};

    while (std::cin >> rules);

    std::map<std::pair<char,char>,unsigned long long> polymer_template{};

    std::map<char,unsigned long long> character_count{};

    for (size_t i = 0;i<polymer_template_input.size()-1;i++) {
        polymer_template[std::make_pair(polymer_template_input[i], polymer_template_input[i+1])]++;
        character_count[polymer_template_input[i]]++;
    }
    character_count[polymer_template_input.back()]++;
    int count_polymerization = 40;
    while (count_polymerization--)
        polymer_template = pair_insertion(&rules,&polymer_template,&character_count);

    std::cout <<(*max_element(character_count.begin(),character_count.end(),
                               [](std::pair<char,unsigned long long> a,std::pair<char,unsigned long long> b) {
                               return a.second<b.second;
                               })).second-
                (*min_element(character_count.begin(),character_count.end(),
                               [](std::pair<char,unsigned long long> a,std::pair<char,unsigned long long> b) {
                                   return a.second<b.second;
                               })).second<<'\n';
    
}
