#include <gtest/gtest.h>
#include "../include/sparse_matrix.h"

TEST(SparseMatrixTest, Constructors) {
    Matrix::SparseMatrix<int> m1;
    EXPECT_TRUE(m1.isEmpty());
    
    Matrix::SparseMatrix<int> m2(5, 5);
    EXPECT_EQ(m2.rows(), 5);
    EXPECT_EQ(m2.cols(), 5);
    EXPECT_EQ(m2.nonZeroCount(), 0);
}

TEST(SparseMatrixTest, ElementAccess) {
    Matrix::SparseMatrix<int> mat(3, 3);
    
    // По умолчанию все элементы 0
    EXPECT_EQ(mat(0, 0), 0);
    EXPECT_EQ(mat(1, 1), 0);
    
    // Устанавливаем ненулевой элемент
    mat(1, 1) = 5;
    EXPECT_EQ(mat(1, 1), 5);
    EXPECT_EQ(mat.nonZeroCount(), 1);
}

TEST(SparseMatrixTest, ApplyLambda) {
    Matrix::SparseMatrix<int> mat(2, 2);
    mat(0, 0) = 1;
    mat(1, 1) = 2;
    
    mat.applyLambda([](int& x) { x *= 2; });
    
    EXPECT_EQ(mat(0, 0), 2);
    EXPECT_EQ(mat(1, 1), 4);
}

TEST(SparseMatrixTest, NonZeroCount) {
    Matrix::SparseMatrix<int> mat(3, 3);
    EXPECT_EQ(mat.nonZeroCount(), 0);
    
    mat(0, 0) = 1;
    mat(1, 1) = 2;
    mat(2, 2) = 3;
    
    EXPECT_EQ(mat.nonZeroCount(), 3);
    
    // Установка элемента в 0 должно удалять его из разреженного представления
    mat(1, 1) = 0;
    EXPECT_EQ(mat.nonZeroCount(), 2);
}

TEST(SparseMatrixTest, FileOperations) {
    Matrix::SparseMatrix<int> original(2, 2);
    original(0, 0) = 1;
    original(1, 1) = 2;
    
    original.saveToFile("test_sparse_matrix.txt");
    
    Matrix::SparseMatrix<int> loaded;
    loaded.loadFromFile("test_sparse_matrix.txt");
    
    EXPECT_EQ(original.rows(), loaded.rows());
    EXPECT_EQ(original.cols(), loaded.cols());
    EXPECT_EQ(original.nonZeroCount(), loaded.nonZeroCount());
}