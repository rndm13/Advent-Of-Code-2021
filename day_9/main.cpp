#include <array>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

struct small_num {
    int val{9};
    small_num() { }
    void operator=(char c){
        switch(c) {
            case '0': val=0; break;
            case '1': val=1; break;
            case '2': val=2; break;
            case '3': val=3; break;
            case '4': val=4; break;
            case '5': val=5; break;
            case '6': val=6; break;
            case '7': val=7; break;
            case '8': val=8; break;
            case '9': val=9; break;
        }
    }  
};
std::stringstream& operator>>(std::stringstream& ss, small_num& sn) {
    char c;
    ss.get(c);
    sn = c;
    return ss;
}
std::stringstream& operator<<(std::stringstream& ss, std::istream& is) {
    std::string s;
    if (is >> s)
        ss << s;
    else ss.setstate(std::ios_base::failbit);
    return ss;
}
int dfs(std::array<std::array<small_num,105>,105> &array_input,int x,int y,std::array<std::array<bool,105>,105>* array_flag) {
    if (array_flag->at(x).at(y)==true || array_input[x][y].val==9)
        return 0;
    array_flag->at(x).at(y)=true;
    return 1+dfs(array_input,x+1,y,array_flag)+dfs(array_input,x-1,y,array_flag)+dfs(array_input,x,y-1,array_flag)+dfs(array_input,x,y+1,array_flag);
}
int main() {
    std::array<std::array<small_num,105>,105> array_input;
    std::stringstream ss;
    size_t indbot{1};
    size_t indright{1};
    while (ss << std::cin) {
        indright = 1;
        while (ss >> array_input[indbot][indright++]); 
        array_input[indbot][indright-1].val=9;
        ss.str(std::string());
        ss.clear();
        indbot++;
    }
    std::array<int,10000> arr_basins;
    auto basins_it = arr_basins.begin();
    for (size_t i = 1;i<indbot;i++) {
        for (size_t j = 1;j<indright-1;j++) {
            if (array_input[i][j].val<array_input[i+1][j].val &&
                array_input[i][j].val<array_input[i-1][j].val && 
                array_input[i][j].val<array_input[i][j+1].val && 
                array_input[i][j].val<array_input[i][j-1].val) {
                std::array<std::array<bool,105>,105> array_flag{false};
                *basins_it++ = dfs(array_input,i,j,&array_flag);
            }
        } 
    }
    std::sort(arr_basins.begin(),basins_it,[](int a,int b){return a>b;});
    std::cout << arr_basins[0]*arr_basins[1]*arr_basins[2];
    return 0;
}
