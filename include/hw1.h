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
    void show(const Matrix& matrix);//remember to add a setw to make more pretty
    Matrix multiply(const Matrix& matrix, double c);
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2);
    Matrix sum(const Matrix& matrix, double c);
    Matrix sum(const Matrix& matrix1, const Matrix& matrix2);// run the tests
    Matrix transpose(const Matrix& matrix);
    Matrix minor(const Matrix& matrix, size_t n, size_t m);
}


#endif //AP_HW1_H
