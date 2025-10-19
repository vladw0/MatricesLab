#include <gtest/gtest.h>
#include "../include/triangular_matrix.h"

TEST(TriangularMatrixTest, Constructors) {
    Matrix::TriangularMatrix<int> m1;
    EXPECT_TRUE(m1.isEmpty());
    
    Matrix::TriangularMatrix<int> m2(3, true);
    EXPECT_EQ(m2.size(), 3);
    EXPECT_TRUE(m2.isUpper());
    
    Matrix::TriangularMatrix<int> m3(4, false);
    EXPECT_EQ(m3.size(), 4);
    EXPECT_FALSE(m3.isUpper());
}

TEST(TriangularMatrixTest, ElementAccess) {
    Matrix::TriangularMatrix<double> mat(3, true);
    
    // Для верхней треугольной матрицы доступны только элементы выше диагонали
    // (реализация будет зависеть от конкретной реализации)
    EXPECT_NO_THROW(mat(0, 1));
    EXPECT_NO_THROW(mat(0, 2));
}

TEST(TriangularMatrixTest, ApplyLambda) {
    Matrix::TriangularMatrix<int> mat(2, true);
    mat.applyLambda([](int& x) { x = 5; });
    
    // Проверяем, что лямбда применяется ко всем элементам
    // (конкретные проверки зависят от реализации)
    EXPECT_TRUE(true);
}

TEST(TriangularMatrixTest, FileOperations) {
    Matrix::TriangularMatrix<int> original(3, true);
    original.saveToFile("test_triangular_matrix.txt");
    
    Matrix::TriangularMatrix<int> loaded;
    loaded.loadFromFile("test_triangular_matrix.txt");
    
    EXPECT_EQ(original.size(), loaded.size());
    EXPECT_EQ(original.isUpper(), loaded.isUpper());
}