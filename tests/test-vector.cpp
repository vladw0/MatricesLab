#include <gtest/gtest.h>
#include "../include/vector.h"

TEST(VectorTest, Constructors) {
    Matrix::Vector<int> v1;
    EXPECT_TRUE(v1.isEmpty());
    
    Matrix::Vector<int> v2(5);
    EXPECT_EQ(v2.size(), 5);
    
    Matrix::Vector<int> v3{1, 2, 3};
    EXPECT_EQ(v3.size(), 3);
    EXPECT_EQ(v3[2], 3);
}

TEST(VectorTest, PushOperations) {
    Matrix::Vector<int> vec{1, 2, 3};
    vec.pushFront(0);
    vec.pushBack(4);
    
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 0);
    EXPECT_EQ(vec[4], 4);
}

TEST(VectorTest, ApplyLambda) {
    Matrix::Vector<int> vec{1, 2, 3};
    vec.applyLambda([](int& x) { x *= 2; });
    
    EXPECT_EQ(vec[0], 2);
    EXPECT_EQ(vec[1], 4);
    EXPECT_EQ(vec[2], 6);
}

TEST(VectorTest, Comparison) {
    Matrix::Vector<int> v1{1, 2, 3};
    Matrix::Vector<int> v2{1, 2, 3};
    Matrix::Vector<int> v3{4, 5, 6};
    
    EXPECT_TRUE(v1 == v2);
    EXPECT_TRUE(v1 != v3);
}

TEST(VectorTest, FileOperations) {
    Matrix::Vector<int> original{1, 2, 3, 4, 5};
    original.saveToFile("test_vector.txt");
    
    Matrix::Vector<int> loaded;
    loaded.loadFromFile("test_vector.txt");
    
    EXPECT_EQ(original, loaded);
}

TEST(VectorTest, BoundsCheck) {
    Matrix::Vector<int> vec{1, 2, 3};
    EXPECT_THROW(vec[5], std::out_of_range);
    EXPECT_THROW(vec[10], std::out_of_range);
}