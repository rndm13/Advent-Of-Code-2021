#include <iostream>
#include <string>
typedef long long ll;
int main()
{
    ll hor=0,ver=0,aim=0;
    std::string s;
    ll x;
    while (std::cin >> s >> x)
    {
        switch(s[0])
        {
        case 'f':
            hor+=x;
            ver+=aim*x;
            break;
        case 'd':
            aim+=x;
            break;
        case 'u':
            aim-=x;
            break;
        }
    }
    std::cout << hor*ver;
}
