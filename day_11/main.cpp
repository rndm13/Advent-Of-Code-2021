#include <sstream>
#include <array>
#include <iostream>
#include <string>
struct digit{
    int value{0};
    void operator=(char c) {
    switch (c) {
        case '0': value = 0; break;
        case '1': value = 1; break;
        case '2': value = 2; break;
        case '3': value = 3; break;
        case '4': value = 4; break;
        case '5': value = 5; break;
        case '6': value = 6; break;
        case '7': value = 7; break;
        case '8': value = 8; break;
        case '9': value = 9; break; }
    }
};
bool check_full_flash(std::array<std::array<bool,10>,10> array_flag) {
    for (int i = 0;i<10;i++) {
        for (int j = 0;j<10;j++) {
            if (!array_flag[i][j])
                return false;
        }
    }
    return true;
}
void update_energy(std::array<std::array<bool,10>,10> *array_flag,std::array<std::array<digit,10>,10> *array_energy, int x, int y) {
    if (x<0 || x>9 || y<0 || y>9 || (*array_flag)[x][y])
        return;
    if (++(*array_energy)[x][y].value>9) {
        (*array_flag)[x][y]=true;
        (*array_energy)[x][y].value=0;
        update_energy(array_flag,array_energy,x+1,y+1);
        update_energy(array_flag,array_energy,x-1,y+1);
        update_energy(array_flag,array_energy,x+1,y-1);
        update_energy(array_flag,array_energy,x-1,y-1);
        update_energy(array_flag,array_energy,x+1,y);
        update_energy(array_flag,array_energy,x-1,y);
        update_energy(array_flag,array_energy,x,y+1);
        update_energy(array_flag,array_energy,x,y-1);
    }
}    
int main() {
    std::array<std::array<digit,10>,10> array_energy;
    size_t index_x{0};
    std::string s;
    while (std::cin >> s) {
        size_t index_y{0};
        for (char c : s)
            array_energy[index_x][index_y++] = c;
        index_x++;
    }
    std::array<std::array<bool,10>,10> array_flag{false};
    size_t step_count = 1;
    while (!check_full_flash(array_flag)) {
        array_flag = {false};
        for (int i = 0;i<10;i++) {
            for (int j = 0;j<10;j++) {
                update_energy(&array_flag,&array_energy,i,j);
            }
        };
        step_count++;
    }
    std::cout << step_count-1;
}
