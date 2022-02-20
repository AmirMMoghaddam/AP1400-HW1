#include "hw1.h"
#include <iostream>
#include <vector> 
#include <random>
#include <iomanip>

using Matrix = std::vector<std::vector<double>>;

namespace algebra{
    Matrix zeros(size_t n, size_t m){
        Matrix A(n);
        for(int i {0};i < n ; i++){
            A[i] = std::vector<double>(m);
            for(int j {0};j < m;j++){
                A[i][j] = 0.0;
            }
        }
        return A;
    }
    Matrix ones(size_t n, size_t m){
        Matrix A(n);
        for(int i {0};i < n ; i++){
            A[i] = std::vector<double>(m);
            for(int j {0};j < m;j++){
                A[i][j] = 1.0;
            }
        }
        return A;
    }
    Matrix random(size_t n, size_t m, double min, double max){
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
    void show(const Matrix& matrix){   
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
    Matrix multiply(const Matrix& matrix, double c){
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
    Matrix multiply(const Matrix& matrix1, const Matrix& matrix2){
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
            if(matrix2.size() == 0){
                return matrix1;
            }
        }
        size_t d {matrix2.size()};
        if(n != d ){
            throw std::logic_error("The dimensions are incorrect!");
        }
        size_t m {matrix1[0].size()};
        size_t k {matrix2[0].size()};
         if(m != k ){
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
        if(a == 0){
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
    double determinant(const Matrix& matrix){
        size_t n {matrix.size()};
        if(n == 0){
            return 1;
        }
        size_t m {matrix[0].size()};
        double result {0};
        if(n != m){
            throw std::logic_error("Matrix is not sqaure !");
        }
        if(n == 2 ){
            result = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        }
        else{
            for(size_t i{0};i < m;i++){
                if(((1+i)%2) == 0){
                    result += matrix[1][i] * algebra::determinant(algebra::minor(matrix,1,i));
                }
                else{
                    result -= matrix[1][i] * algebra::determinant(algebra::minor(matrix,1,i));
                }
            }
        }
        return result;
    }
    Matrix inverse(const Matrix& matrix){
        size_t n {matrix.size()};
        if(n == 0){
            return matrix;
        }
        size_t m {matrix[0].size()};
        double det {algebra::determinant(matrix)};
        if(det == 0){
            throw std::logic_error("determinant is zero !");
        }
        Matrix adj(n);
        Matrix result(n);
        result = algebra::zeros(n,n);
        adj = algebra::zeros(n,n);

         for(size_t i{0};i < n;i++){
            for(size_t j{0};j < n;j++){
                if(((j+i)%2) == 0){
                   adj[i][j] = algebra::determinant(algebra::minor(matrix,i,j));
                }
                else{
                    adj[i][j] = - 1 * algebra::determinant(algebra::minor(matrix,i,j));
                }
                
            }
        }
        result = algebra::multiply(algebra::transpose(adj),1/det);
        return result;
        
    }
    Matrix concatenate(const Matrix& matrix1, const Matrix& matrix2, int axis){
        size_t n {matrix1.size()};
        if(n == 0){
            throw std::logic_error("matrix is empty!");
        }
        size_t m {matrix1[0].size()};
        size_t d {matrix2.size()};
        if(d == 0){
            throw std::logic_error("matrix is empty!");
        }
        size_t k {matrix2[0].size()};
        if(axis == 1){
            if( n != d){
                throw std::logic_error("dimensions are incorrect !");
            }
            Matrix result(n);
            result = algebra::zeros(n,m+k);
            for(size_t i{0};i < n;i++){
                for(size_t j{0};j < m+d;j++){
                    if(j >= m){
                        result[i][j] = matrix2[i][j-m] ;
                    }
                    else{
                        result[i][j] = matrix1[i][j] ;
                    }
                    
                }
            }
           
            return result;
        }
        else if(axis == 0){
            if( m != k){
                throw std::logic_error("dimensions are incorrect !");
            }
            Matrix result(n+d);
            result = algebra::zeros(n+d,m);
            for(size_t i{0};i < n+d;i++){
                for(size_t j{0};j < m;j++){
                   if(i >= n){
                        result[i][j] = matrix2[i-n][j] ;
                    }
                    else{
                        result[i][j] = matrix1[i][j] ;
                    }
                }
            }
            return result;
        }
        
        else{
            throw std::logic_error("axis have incorrect value!");
        }
    }
    Matrix ero_swap(const Matrix& matrix, size_t r1, size_t r2){
        size_t r {matrix.size()};
        if(r == 0 || r1 >= r || r2 >= r){
            throw std::logic_error("the input is incorrect !");
        }
        size_t c {matrix[0].size()};
        Matrix result(r);
        result = algebra::zeros(r,c);
        result[r1] = std::vector<double> {matrix[r2]};
        result[r2] = std::vector<double> {matrix[r1]};
        for(size_t i{0};i < r;i++){
            for(size_t j{0};j < c;j++){
                if(i != r1 && i != r2){
                     result[i][j] = matrix[i][j] ;
                }
               
            }
        }
        return result;
    }
    Matrix ero_multiply(const Matrix& matrix, size_t r, double c){
        size_t ros {matrix.size()};
        if(ros == 0 || r >= ros ){
            throw std::logic_error("the input is incorrect !");
        }
        size_t cols {matrix[0].size()};
        Matrix result(ros);
        result = algebra::zeros(ros,cols);
        for(size_t i{0};i < ros;i++){
            for(size_t j{0};j < cols;j++){
                if(i != r){
                    result[i][j] = matrix[i][j] ;
                }
                else{
                    result[i][j] = matrix[i][j] * c;
                }
               
            }
        }
        return result;
    }
    Matrix ero_sum(const Matrix& matrix, size_t r1, double c, size_t r2){
        size_t ros {matrix.size()};
        if(ros == 0 || r1 >= ros || r2 >= ros){
            throw std::logic_error("the input is incorrect !");
        }
        size_t cols {matrix[0].size()};
        std::vector<double> RowCache(cols);
        // put r1 in Row chache :
        RowCache = matrix[r1];
        Matrix result(ros);
        result = algebra::zeros(ros,cols);
        for(size_t i{0};i < cols;i++){
            RowCache[i] = RowCache[i] * c;
        }
        for(size_t i{0};i < ros;i++){
            for(size_t j{0};j < cols;j++){
                if(i != r2){
                    result[i][j] = matrix[i][j];
                }
                else{
                    result[i][j] = matrix[i][j] + RowCache[j];
                }
               
            }
        
        }
        return result;
    }
    Matrix upper_triangular(const Matrix& matrix){
        size_t ros {matrix.size()};
        if(ros == 0 ){
            return matrix;
        }
        size_t cols {matrix[0].size()};
        if(ros != cols){
            throw std::logic_error("matrix is not square !");
        }
        std::vector<double> RowZero(ros);
        Matrix result(ros);
        result = matrix;
        if( result[0][0] == 0){
            for(size_t i{1};i < ros;i++){
                if(matrix[i][0] != 0){
                    result = algebra::ero_sum(result,i,1,0);
                    break;
                }
            }
        }
        for(size_t i{1};i < ros;i++){
            for(size_t j{0};j < cols;j++){
                if(j < i){
                    if(result[j][j] == 0){
                        for(size_t k{j};k < ros;k++){
                            if(matrix[k][j] != 0){
                                result = algebra::ero_sum(result,k,1,j);
                            }
                        }
                        double a = (result[i][j] / result[j][j]) * -1;
                        result = algebra::ero_sum(result,j,a,i); 
                    }
                    else{
                        double a = (result[i][j] / result[j][j]) * -1;
                        result = algebra::ero_sum(result,j,a,i); 
                    }
                }
            }
        }
        return result;
    }

}

