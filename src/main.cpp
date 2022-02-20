
#include <iostream>
#include <gtest/gtest.h>
#include <random>
#include "hw1.h"

using Matrix = std::vector<std::vector<double>>;

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
       
        // int m {3};
        // double c {10};
        // double min {1.0};
        // double max {10.0};
        // Matrix B(n);
        // B = algebra::random(n,m,min,max);
        // std::cout << "the original matrix1 is : " << std::endl;
        // algebra::show(B);
        // Matrix C(n);
        // C = algebra::random(2,3,min,max);
        // std::cout << "the original matrix2 is : " << std::endl;
        // algebra::show(C);
        // std::cout << "the result matrix is : " << std::endl;
        // Matrix D(n);
        // D = algebra::transpose(B);
        // algebra::show(D);
        // std::cout << "rows : " << B.size() << std::endl;
        // std::cout << "columns : " << B[0].size() << std::endl;
        // for(size_t i {0};i < 2 ; i++){
        //     for(size_t j {0};j < 3;j++){
        //         std::cout << B[i][j] << " " ;
        //     }
        //     std::co
       Matrix matrix2{{0, 2, 3}, {4, 7, 5}, {6, 1, 3}};
       Matrix res2{algebra::upper_triangular(matrix2)};
       std::cout << "matrix1 : "  << std::endl;
       algebra::show(matrix2);
       std::cout << "res : "  << std::endl;
       algebra::show(res2);
       
    //    for(size_t i{0};i<matrix1[0].size();i++){
    //         std::cout << RowCache[i] << " " ;
    //    }
    //    std::cout << std::endl;
        
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