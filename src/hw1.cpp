#include "hw1.h"
#include <iostream>
#include <vector> 
#include <random>
#include <iomanip>

using Matrix = std::vector<std::vector<double>>;

namespace algebra{
    Matrix zeros(size_t n, size_t m)
    {
        Matrix A(n);
        for(int i {0};i < n ; i++){
            A[i] = std::vector<double>(m);
            for(int j {0};j < m;j++){
                A[i][j] = 0.0;
            }
        }
        return A;
    }
    Matrix ones(size_t n, size_t m)
    {
        Matrix A(n);
        for(int i {0};i < n ; i++){
            A[i] = std::vector<double>(m);
            for(int j {0};j < m;j++){
                A[i][j] = 1.0;
            }
        }
        return A;
    }
    Matrix random(size_t n, size_t m, double min, double max)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(min, max);
        Matrix A(n);
        for(int i {0};i < n ; i++){
            A[i] = std::vector<double>(m);
            for(int j {0};j < m;j++){
                A[i][j] = dist(mt);
            }
        }
        return A;

    }
    void show(const Matrix& A)
    {
        size_t n {A.size()};
        size_t m {A[0].size()};
         for(size_t i {0};i < n; i++){
            for(size_t j {0};j < m;j++){
                std::cout << std::setprecision(3) << A[i][j] << " " ;
            }
            std::cout << std::endl;
    }
}
}

