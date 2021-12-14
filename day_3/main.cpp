#include <bits/stdc++.h>

#define BITLENGTH 12

using namespace std;

typedef long long ll;
vector <ll> count_1(BITLENGTH);
int main()
{

    vector<bitset<BITLENGTH>> input;
    bitset<BITLENGTH> bits;
    while(cin >> bits)
    {
        input.push_back(bits);
        for (int i = BITLENGTH-1; i>=0; i--)
            if (bits[i])
                count_1[i]++;
    }
    vector<bitset<BITLENGTH>>  oxygen = input;
    vector <ll> o2_count_1  = count_1;
    vector<bitset<BITLENGTH>>  co2 = input;
    vector <ll> co2_count_1 = count_1;
    for (int index = BITLENGTH-1; oxygen.size()>1; index--)
    {
        bool majority = o2_count_1[index]>=(oxygen.size()+1)/2;
        for (int i = 0; i<oxygen.size(); i++)
        {
            if (oxygen[i][index]!=majority)
            {
                for (int j = BITLENGTH-1; j>=0; j--)
                    if (oxygen[i][j])
                        o2_count_1[j]--;
                oxygen.erase(oxygen.begin()+i--);
            }
        }
    }
    for (int index = BITLENGTH-1; co2.size()>1; index--)
    {
        bool minority = co2_count_1[index]<(co2.size()+1)/2;
        for (int i = 0; i<co2.size(); i++)
        {
            if (co2[i][index]!=minority)
            {
                for (int j = BITLENGTH-1; j>=0; j--)
                    if (co2[i][j])
                        co2_count_1[j]--;
                co2.erase(co2.begin()+i--);
            }
        }
    }
    cout << oxygen[0]<<' '<<co2[0]<<'\n'<< oxygen[0].to_ullong() * co2[0].to_ullong();
}
