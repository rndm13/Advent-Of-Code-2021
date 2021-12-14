#include <iostream>
#include <array>

int main() {
    std::array<int,10000> array_input{};
    int array_count{};
    while (std::cin>>array_input[array_count++]);
    array_count--;
    int result_count{};
    for (int i = 0;i<array_count-2;i++)
        if (array_input[i]+array_input[i+1]+array_input[i+2]<array_input[i+1]+array_input[i+2]+array_input[i+3])
            result_count++;
    std::cout << result_count;
    return 0;
}
