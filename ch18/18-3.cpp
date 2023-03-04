#include <ios>
#include<iostream>

template<typename T>
long double sum_value(const T & t){
    return t;
}
template<typename T, typename... Args>
long double sum_value(const T & t, const Args&... args){
    return t + sum_value(args...);
}

int main() {
    std::cout << sum_value(1,2,3,4,5) << std::endl;
    std::cout << sum_value(1,2,3,4,5,6,7) << std::endl;;
    std::cout.precision(5);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout << sum_value(1,2,3,4,5,6,7,8,9) << std::endl;
    return 0;
}