
#include <iostream>
#include <gtest/gtest.h>
#include "hw1.h"

using Matrix = std::vector<std::vector<double>>;

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        int n {2};
        int m {3};
        Matrix B(n);
        B = algebra::zeros(n,m);
        for(size_t i {0};i < 2 ; i++){
            for(size_t j {0};j < 3;j++){
                std::cout << B[i][j] << " " ;
            }
            std::cout << std::endl;
        }
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}