#ifndef AP_HW1_H
#define AP_HW1_H
#include <vector> 
#include <random>
#include <iomanip>
#include <iostream>


using Matrix = std::vector<std::vector<double>>;

namespace algebra{
    Matrix zeros(std::size_t n, std::size_t m);
    Matrix ones(std::size_t n, std::size_t m);   
    Matrix random(std::size_t n, std::size_t m, double min, double max);
    void show(const Matrix& matrix);
}


#endif //AP_HW1_H
