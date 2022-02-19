
#include <iostream>
#include <gtest/gtest.h>
#include <random>
#include "hw1.h"

using Matrix = std::vector<std::vector<double>>;

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
       
        int n {2};
        int m {3};
        double c {10};
        double min {1.0};
        double max {10.0};
        Matrix B(n);
        B = algebra::random(n,m,min,max);
        std::cout << "the original matrix1 is : " << std::endl;
        algebra::show(B);
        Matrix C(n);
        C = algebra::random(2,3,min,max);
        std::cout << "the original matrix2 is : " << std::endl;
        algebra::show(C);
        std::cout << "the result matrix is : " << std::endl;
        Matrix D(n);
        D = algebra::sum(B,C);
        algebra::show(D);
        // std::cout << "rows : " << B.size() << std::endl;
        // std::cout << "columns : " << B[0].size() << std::endl;
        // for(size_t i {0};i < 2 ; i++){
        //     for(size_t j {0};j < 3;j++){
        //         std::cout << B[i][j] << " " ;
        //     }
        //     std::cout << std::endl;
        // }

        
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