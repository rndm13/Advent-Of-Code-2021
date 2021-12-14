#include <iostream>
#include <string>
#include <regex>
using namespace std;
istream& operator>> (istream& is, int board[5][5]) {
    for (int i = 0;i<5;i++)
        for (int j = 0;j<5;j++)
            is >> board[i][j];
    return is;
}
ostream& operator<< (ostream& os,bool matched[5][5]) {
    for (int i = 0;i<5;i++) {
        for (int j = 0;j<5;j++)
            os << matched[i][j];
        os << '\n';
    }
    return os;
}
bool check_match(bool matched[5][5],int x,int y) {
    for (int i = 0;i<5;i++)
        if (!matched[x][i] ) {
            for (int i = 0;i<5;i++)
                if (!matched[i][y] ) {
                    return false;
                }
            return true;
        }
    return true;
}
int main() {
    string s;
    cin >> s;
    cout << s <<'\n';
    regex numbers_only(R"abc(\d+)abc");
    regex_token_iterator<string::iterator> rend;
    regex_token_iterator<string::iterator> rit (s.begin(),s.end(),numbers_only,0);
    vector<int> vec_numbers;
    while (rit!=rend)
        vec_numbers.push_back(stoi(rit++->str()));
    
    int board[5][5];
    size_t min_solve_turns=0;
    int solve_score=0;
    while (cin >> board) {
        int sum=0;
        for (int i = 0;i<5;i++)
            for (int j = 0;j<5;j++)
                sum+=board[i][j];
        bool matched[5][5] = {0};
        bool match = 0;
        int k;
        for (k = 0;k<vec_numbers.size() && !match;k++)
            for (int i = 0;i<5;i++)
                for (int j = 0;j<5;j++)
                    if (board[i][j]==vec_numbers[k]) {
                        matched[i][j]=1;
                        sum-=board[i][j];
                        match = check_match(matched,i,j);
                    }
        if (match && min_solve_turns < k) {
            solve_score=sum*vec_numbers[k-1];
            min_solve_turns = k-1;
        }
        cout << matched<<'\n';
        cout << solve_score <<' '<<min_solve_turns<<'\n';
    }
    cout << solve_score<<'\n';
}
