#include <gtest/gtest.h>
#include "../include/square_matrix.h"

TEST(SquareMatrixTest, Constructors) {
    Matrix::SquareMatrix<int> m1;
    EXPECT_TRUE(m1.isEmpty());
    
    Matrix::SquareMatrix<int> m2(3);
    EXPECT_EQ(m2.size(), 3);
    
    Matrix::SquareMatrix<int> m3{
        {1, 2},
        {3, 4}
    };
    EXPECT_EQ(m3.size(), 2);
    EXPECT_EQ(m3(1, 1), 4);
}

TEST(SquareMatrixTest, ArithmeticOperations) {
    Matrix::SquareMatrix<int> m1{
        {1, 2},
        {3, 4}
    };
    
    Matrix::SquareMatrix<int> m2{
        {5, 6},
        {7, 8}
    };
    
    auto sum = m1 + m2;
    Matrix::SquareMatrix<int> expected_sum{
        {6, 8},
        {10, 12}
    };
    EXPECT_EQ(sum, expected_sum);
    
    auto diff = m1 - m2;
    Matrix::SquareMatrix<int> expected_diff{
        {-4, -4},
        {-4, -4}
    };
    EXPECT_EQ(diff, expected_diff);
}

TEST(SquareMatrixTest, Multiplication) {
    Matrix::SquareMatrix<int> m1{
        {1, 2},
        {3, 4}
    };
    
    Matrix::SquareMatrix<int> m2{
        {2, 0},
        {1, 2}
    };
    
    auto product = m1 * m2;
    Matrix::SquareMatrix<int> expected{
        {4, 4},
        {10, 8}
    };
    EXPECT_EQ(product, expected);
}

TEST(SquareMatrixTest, ApplyLambda) {
    Matrix::SquareMatrix<int> mat{
        {1, 2},
        {3, 4}
    };
    
    mat.applyLambda([](int& x) { x += 10; });
    
    EXPECT_EQ(mat(0, 0), 11);
    EXPECT_EQ(mat(0, 1), 12);
    EXPECT_EQ(mat(1, 0), 13);
    EXPECT_EQ(mat(1, 1), 14);
}

TEST(SquareMatrixTest, SpecialOperations) {
    Matrix::SquareMatrix<int> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    EXPECT_EQ(mat.trace(), 15);
    
    auto transposed = mat.transpose();
    EXPECT_EQ(transposed(0, 1), 4);
    EXPECT_EQ(transposed(1, 0), 2);
}

TEST(SquareMatrixTest, FileOperations) {
    Matrix::SquareMatrix<int> original{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    original.saveToFile("test_square_matrix.txt");
    
    Matrix::SquareMatrix<int> loaded;
    loaded.loadFromFile("test_square_matrix.txt");
    
    EXPECT_EQ(original, loaded);
}

TEST(SquareMatrixTest, InvalidOperations) {
    Matrix::SquareMatrix<int> m1(2);
    Matrix::SquareMatrix<int> m2(3);
    
    EXPECT_THROW(m1 + m2, std::invalid_argument);
    EXPECT_THROW(m1 - m2, std::invalid_argument);
    EXPECT_THROW(m1 * m2, std::invalid_argument);
    
    EXPECT_THROW(m1(5, 5), std::out_of_range);
}