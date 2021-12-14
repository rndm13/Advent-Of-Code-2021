#include <iostream>
#include <map>
#include <string>
typedef std::pair<int,int> point;
point parse_string(std::string pair_string) {
    int first,second;
    first = std::stoi(pair_string.substr(0,pair_string.find(',')));
    second = std::stoi(pair_string.substr(pair_string.find(',')+1,10));
    return {first,second};
}
struct line {
    point p1,p2;
    line(){}
    bool is_straight() {
    return p1.first==p2.first || p1.second==p2.second;
    }
    bool is_diagonal() {
    return abs(p1.first-p2.first)==abs(p1.second-p2.second);
    }
};
std::istream& operator>>(std::istream &is, point &p) {
    std::string s;
    is >> s;
    if (!s.empty())
        p = parse_string(s);
    return is;
}
std::istream& operator>>(std::istream &is, line &l) {
    is >> l.p1; is.ignore(2,'>'); is >> l.p2;
    return is;
}
void process_straight_line(line l, std::map<point,int> &map_count) {
    if (l.p1.first>l.p2.first)
        std::swap(l.p1.first,l.p2.first);
    if (l.p1.second>l.p2.second)
        std::swap(l.p1.second,l.p2.second);
    for (int i = l.p1.first;i<=l.p2.first;i++)
        for (int j = l.p1.second;j<=l.p2.second;j++)
            map_count[point(i,j)]++;
}
void process_diagonal_line(line l, std::map<point,int> &map_count) {
    if (l.p1.first>l.p2.first) {
        std::swap(l.p1.first,l.p2.first);
        std::swap(l.p1.second,l.p2.second);
    }
    for (int i = 0;i<=l.p2.first-l.p1.first;i++) {
        map_count[point(l.p1.first+i,l.p1.second+((l.p1.second<l.p2.second)?i:-i))]++;
        //std::cout <<"\t\t"<<l.p1.first+i<<','<<l.p1.second+((l.p1.second<l.p2.second)?i:-i)<<'\n';
    }
}
int main() {
    std::map<point,int> map_count; 
    line input_line;
    while(std::cin >> input_line) {
        if (input_line.is_straight()) {
            //std::cout <<"\tstraight\n";
            process_straight_line(input_line, map_count);
        }
        else if (input_line.is_diagonal()) {
            //std::cout <<"\tdiagonal\n";
            process_diagonal_line(input_line, map_count);
        }
    }
    long long sum = 0;
    for (auto [key,value] : map_count)
        if (value>=2)
            sum++;
    std::cout << sum;
}
