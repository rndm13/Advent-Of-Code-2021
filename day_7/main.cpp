#include <iostream>
#include <cmath>
#include <array>
#include <string>
#include <regex>
#include <functional>
int main() {
    std::array<int,5000> input_array{};
    auto iter_array = input_array.begin();
    std::string input;
    std::cin >> input;
    std::regex numbers_only(R"(\d+)");
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> rit (input.begin(),input.end(),numbers_only,0);
    while (rit!=rend)
        *iter_array++=std::stoi(rit++->str());
    std::sort(input_array.begin(),iter_array);
    long long avg = 0;
    size_t cnt = std::distance(input_array.begin(),iter_array);
    for (auto it = input_array.begin();it!=iter_array;it++)
        avg+=*it;
    avg=(avg+cnt-1)/cnt;
    long long mnsum = 9999999999999,sum=0;
    for (int offset = -5;offset<5;offset++) {
        sum = 0;
        for (auto it = input_array.begin();it!=iter_array;it++) {
            int dist = abs(*it-avg+offset);
            sum+=dist*(dist+1)/2;
        }
        mnsum = std::min(mnsum,sum);
    }
    std::cout << mnsum;
}
