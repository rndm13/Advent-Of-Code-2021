#include <iostream>
#include <numeric>
#include <array>
#include <string>
#include <regex>
std::array<long long,9> simulate_day(std::array<long long,9> cnt_age) {
    std::array<long long,9> new_cnt_age{0};
    for (int i = 1;i<9;i++)
        new_cnt_age[i-1]=cnt_age[i];
    new_cnt_age[6]+=cnt_age[0];
    new_cnt_age[8]=cnt_age[0];
    return new_cnt_age;
} 
int main()
{
    std::array<long long,9> cnt_age{0};
    std::string input;
    std::cin >> input;
    std::regex numbers_only(R"abc(\d+)abc");
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> rit (input.begin(),input.end(),numbers_only,0);
    while (rit!=rend)
        cnt_age[std::stoi(rit++->str())]++;
    int days=256;
    while (days--)
        cnt_age = simulate_day(cnt_age);
    long long sum = 0;
    for (size_t i = 0;i<cnt_age.size();i++)
        sum+=cnt_age[i];
    std::cout << sum;
}
