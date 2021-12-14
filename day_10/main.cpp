#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
std::map <char, int> value_table {
    {')',1},
    {']',2},
    {'}',3},
    {'>',4},
    {'(',-1},
    {'[',-2},
    {'{',-3},
    {'<',-4}
};
long long string_value(std::string input) {
    std::stack<int> brackets;
    for (size_t i = 0;i<input.size();i++) {
        if (value_table[input[i]]<0)
            brackets.push(value_table[input[i]]);
        else if (-brackets.top() != value_table[input[i]]) {
            return 0;
        }
        else brackets.pop();
    }
    long long result=0;
    while (!brackets.empty()) {
        result*=5;
        result+=-brackets.top();
        brackets.pop();
    }
    return result;
}
int main() {
    std::vector<long long> vec_res;
    std::string input;
    while (std::cin >> input) {
        if (string_value(input)) {
            vec_res.push_back(string_value(input));
        }
    }
    sort (vec_res.begin(),vec_res.end());
    std::cout << vec_res[vec_res.size()/2];
}
