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
        if( min >= max)
            throw std::logic_error("Min is greater than Max!");
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
    void show(const Matrix& matrix)
    {   
        size_t n {matrix.size()};
        if(n == 0){
            std::cout << "matrix is empty" << std::endl;
        }
        else{
        size_t m {matrix[0].size()};
         for(size_t i {0};i < n; i++){
            for(size_t j {0};j < m;j++){
                std::cout << std::setprecision(3) << matrix[i][j] << " " ;
            }
            std::cout << std::endl;
        }
        }

    }
    Matrix multiply(const Matrix& matrix, double c)
    {
        size_t n {matrix.size()};
         if(n == 0){
            return Matrix {};
        }
        size_t m {matrix[0].size()};
        Matrix result(n);
        result = algebra::zeros(n,m);
        for(size_t i{0};i < n;i++){
            for(size_t j{0};j < m;j++){
                result[i][j] = matrix[i][j] * c ;
            }
        }
        return result;

    }
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2)
    {
        size_t n {matrix1.size()};
        if(n == 0){
            return Matrix {};
        }
        size_t m {matrix1[0].size()};
        size_t d {matrix2.size()};
        if(d == 0){
            return Matrix {};
        }
        size_t k {matrix2[0].size()};
        Matrix result(n);
        result = algebra::zeros(n,k);
        double sum {0};
        if(m != d)
            throw std::logic_error("The dimensions are incorrect!");
        for(size_t i{0};i < n;i++){
            for(size_t j{0};j < k;j++){
                double sum = 0;
                for(size_t l{0};l < m;l++){
                    sum += matrix1[i][l] * matrix2[l][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }
    Matrix sum(const Matrix& matrix, double c){
        size_t n {matrix.size()};
        if(n == 0){
            return Matrix {};
        }
        size_t m {matrix[0].size()};
        Matrix result(n);
        result = algebra::zeros(n,m);
        for(size_t i{0};i < n;i++){
            for(size_t j{0};j < m;j++){
                result[i][j] = matrix[i][j] + c ;
            }
        }
        return result;
    }
    Matrix sum(const Matrix& matrix1, const Matrix& matrix2){
        size_t n {matrix1.size()};
        if(n == 0){
            return matrix2;
        }
        size_t m {matrix1[0].size()};
        size_t d {matrix2.size()};
        if(d == 0){
            return matrix1;
        }
        size_t k {matrix2[0].size()};
        if(n != d || m != k){
            throw std::logic_error("The dimensions are incorrect!");
        }

        Matrix result(n);
        result = algebra::zeros(n,k);
        for(size_t i{0};i < n;i++){
            for(size_t j{0};j < m;j++){
                result[i][j] = matrix1[i][j] + matrix2[i][j] ;
            }
        }
        return result;
    }
    Matrix transpose(const Matrix& matrix){
        size_t n {matrix.size()};
        if(n == 0){
            return matrix;
        }
        size_t m {matrix[0].size()};
        Matrix result(m);
        result = algebra::zeros(m,n);
        for(size_t i{0};i < n;i++){
            for(size_t j{0};j < m;j++){
                result[j][i] = matrix[i][j] ;
            }
        }
        return result;
    }
    Matrix minor(const Matrix& matrix, size_t n, size_t m){
        size_t a {matrix.size()};
        if(n == 0){
            return matrix;
        }
        size_t b {matrix[0].size()};
        Matrix result(a-1);
        result = algebra::zeros(a-1,b-1);
        for(size_t i{0};i < a;i++){   
            if(i != n){
                for(size_t j{0};j < b;j++){
                    if(j != m){
                        if(i < n ){
                            if(j < m){
                                result[i][j] = matrix[i][j] ;
                            }
                            else{
                                result[i][j-1] = matrix[i][j] ;
                            }
                        }
                        else{
                            if(j < m){
                                result[i-1][j] = matrix[i][j] ;
                            }
                            else{
                                result[i-1][j-1] = matrix[i][j] ;
                            }
                        }
                    }
                }
                
            }
        }
        return result;
    }


}

