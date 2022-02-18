#include "hw1.h"
#include <vector> 

using Matrix = std::vector<std::vector<double>>;

namespace algebra{
    Matrix zeros(std::size_t n, std::size_t m)
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
    Matrix ones(std::size_t n, std::size_t m)
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
}

