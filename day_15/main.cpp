#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <string>
#include <cmath>

struct digit {
    short value : 5;
    void operator=(char c) {
        value = c-'0';
    }
    int operator+(int x) {
        int res = value;
        res+=x;
        if (res>9) {
            res%=10;
            res++;
        }
        return res;
    }
};

constexpr long long MAX = 999999999;

std::istream& operator>>(std::istream& is,std::array<digit,100*5+2> &input) {
    std::string s;
    is >> s;
    for (size_t i = 1;i<=s.size();i++){
        input[i]=s[i-1];
        for (size_t j = 1;j<5;j++) {
            input[i+j*s.size()].value=input[i]+j;
        }
        
    }
    return is;
}

template <typename Head>
Head pack_min(Head a,Head b) {
    return std::min(a,b);
}
template <typename Head,typename ...Tail>
Head pack_min(Head h,Tail... t) {
    return std::min(h,pack_min(t...));
}

int main() {
    std::array<std::array<digit,100*5+2>,100*5+2> risk{}; 

    std::array<std::array<int,100*5+2>,100*5+2> total_risk;

    size_t bottom{1}, right{1};

    while(std::cin >> risk[bottom++]);

    for (;risk[1][right].value>0;right++);

    bottom-=2;
    right/=5;

    for (size_t i = 1;i<=bottom;i++) {
        for (size_t j = 1;j<=right*5;j++) {
            for (size_t iexp = 1;iexp < 5;iexp++) {
                risk[i+iexp*bottom][j].value=risk[i][j]+iexp;
            }
        }
    }
    for (size_t i = 0;i<=bottom*5+1;i++) {
        for (size_t j = 0;j<=right*5+1;j++) {
            total_risk[i][j] = MAX; 
        }
    }
    total_risk[1][1]=0; 
    bool change = true;
    while (change) {
        change=false; 
        for (size_t i = 1;i<=5*bottom;i++) {
            for (size_t j = 1;j<=5*right;j++) {
                auto old_risk = total_risk[i][j];
                total_risk[i][j]=pack_min( old_risk, 
                        risk[i][j].value + total_risk[i+1][j],
                        risk[i][j].value + total_risk[i-1][j],
                        risk[i][j].value + total_risk[i][j+1],
                        risk[i][j].value + total_risk[i][j-1]); 
                if (total_risk[i][j]<0)
                    total_risk[i][j]=old_risk;
                if (old_risk > total_risk[i][j])
                    change=true;
            }
        }
    }
    std::cout << total_risk[5*bottom][5*right];
}
