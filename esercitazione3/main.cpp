# include <concepts>
# include <iostream>
# include "header.hpp"
int main(void)
{
    rational<int> r1(5,0);
    rational<int> r2(-5,0);
    rational<int> r = r1+ r2;
    std::cout << r << "\n";
    return 0;
}