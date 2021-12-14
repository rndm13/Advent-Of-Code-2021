#include <iostream>
#include <cmath>
#include <iterator>
#include <map>
#include <algorithm>
#include <string>
#include <array>
std::istream& operator>>(std::istream &is, std::array<std::string, 15> &input) {
    for (int i = 0;i<15;i++)
        is >> input.at(i);
    return is;
}
int main() {
    std::array<std::string, 15> input_line;
    long long sum = 0;
    while (std::cin >> input_line) {
        std::map<int,std::string> sets;
        sets[8]="abcdefg";
        for (int i = 0;i<11;i++) {
            sort(input_line[i].begin(),input_line[i].end());
            switch(input_line[i].size()) { 
                case 2:
                sets[1]=input_line[i];
                break;
                case 3:
                sets[7]=input_line[i];
                break;
                case 4:
                sets[4]=input_line[i];
                break;
            }
        }
        std::set_difference(sets[7].begin(),sets[7].end(),
                            sets[1].begin(),sets[1].end(),
                            std::back_inserter(sets[-1]));

        std::set_difference(sets[4].begin(),sets[4].end(),
                            sets[1].begin(),sets[1].end(),
                            std::back_inserter(sets[-42]));

        std::set_union(     sets[4].begin(),sets[4].end(),
                            sets[7].begin(),sets[7].end(),
                            std::back_inserter(sets[-8]));
        sets[-30]=sets[8];
        sets[-69]=sets[8];
        std::set_difference(sets[8].begin(),sets[8].end(),
                            sets[4].begin(),sets[4].end(),
                            std::back_inserter(sets[-21]));

        std::set_difference(sets[-21].begin(),sets[-21].end(),
                            sets[-1].begin(),sets[-1].end(),
                            std::back_inserter(sets[-20]));

        for (int i = 0;i<11;i++) {
            if (input_line[i].size() == 5) {
                sets[-235]=input_line[i];
                std::string str;
                std::set_intersection( sets[-30].begin(),sets[-30].end(),
                                       sets[-235].begin(),sets[-235].end(),
                                       std::back_inserter(str));
                sets[-30]=str;
            }
            if (input_line[i].size() == 6) {
                sets[-690]=input_line[i];
                std::string str;
                std::set_intersection( sets[-69].begin(),sets[-69].end(),
                                       sets[-690].begin(),sets[-690].end(),
                                       std::back_inserter(str));
                sets[-69]=str;
            }
        }
        std::set_union(sets[-30].begin(),sets[-30].end(),
                       sets[1].begin(),sets[1].end(),
                       std::back_inserter(sets[3]));
        std::set_intersection(sets[-30].begin(),sets[-30].end(),
                              sets[-42].begin(),sets[-42].end(),
                              std::back_inserter(sets[-7]));
        std::set_difference  (sets[-42].begin(),sets[-42].end(),
                              sets[-7].begin(),sets[-7].end(),
                              std::back_inserter(sets[-6]));
        std::set_intersection(sets[-30].begin(),sets[-30].end(),
                              sets[-20].begin(),sets[-20].end(),
                              std::back_inserter(sets[-4]));
        std::set_difference  (sets[-20].begin(),sets[-20].end(),
                              sets[-4].begin(),sets[-4].end(),
                              std::back_inserter(sets[-5]));
        std::set_difference  (sets[1].begin(),sets[1].end(),
                              sets[-69].begin(),sets[-69].end(),
                              std::back_inserter(sets[-2]));
        std::set_difference  (sets[1].begin(),sets[1].end(),
                              sets[-2].begin(),sets[-2].end(),
                              std::back_inserter(sets[-3]));
        sets[2]=sets[-1]+sets[-2]+sets[-7]+sets[-5]+sets[-4];
        sets[5]=sets[-1]+sets[-6]+sets[-7]+sets[-3]+sets[-4];
        sets[6]=sets[5]+sets[-5];
        sets[0]=sets[-1]+sets[-2]+sets[-3]+sets[-4]+sets[-5]+sets[-6];
        sets[9]=sets[5]+sets[-2];
        //for (auto [key,value] :sets)
            //std::cout << key <<' '<<value<<'\n';
        for (int i = 0 ;i<=9;i++) {
            sort(sets[i].begin(),sets[i].end());
            //std::cout << i <<' '<<sets[i]<<'\n';
        }
        int ans = 0;
        for (int i = 11;i<15;i++) {
            sort(input_line[i].begin(),input_line[i].end());
            for (int j = 0;j<=9;j++)
               if (sets[j]==input_line[i])
                  ans+=std::pow(10,14-i)*j;
        }
        std::cout << ans <<'\n';
        sum+=ans; 
    }
    std::cout << sum <<'\n';
    return 0;
}
