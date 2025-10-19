#include <iostream>
#include "../include/vector.h"
#include "../include/square_matrix.h"
#include "../include/triangular_matrix.h"
#include "../include/sparse_matrix.h"

using namespace Matrix;

void demoVector() {
    std::cout << "=== VECTOR DEMO ===" << std::endl;
    
    Vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "Original: " << vec << std::endl;
    
    vec.pushFront(0);
    vec.pushBack(6);
    std::cout << "After push operations: " << vec << std::endl;
    
    vec.applyLambda([](int& x) { x *= 2; });
    std::cout << "After lambda (x * 2): " << vec << std::endl;
}

void demoSquareMatrix() {
    std::cout << "\n=== SQUARE MATRIX DEMO ===" << std::endl;
    
    SquareMatrix<int> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    std::cout << "Matrix:\n" << mat << std::endl;
    std::cout << "Trace: " << mat.trace() << std::endl;
    
    auto transposed = mat.transpose();
    std::cout << "Transposed:\n" << transposed << std::endl;
}

void demoTriangularMatrix() {
    std::cout << "\n=== TRIANGULAR MATRIX DEMO ===" << std::endl;
    
    TriangularMatrix<double> upper(3, true);
    std::cout << "Upper triangular matrix created, size: " << upper.size() << std::endl;
}

void demoSparseMatrix() {
    std::cout << "\n=== SPARSE MATRIX DEMO ===" << std::endl;
    
    SparseMatrix<int> sparse(5, 5);
    std::cout << "Sparse matrix created: " << sparse.rows() << "x" << sparse.cols() << std::endl;
}

int main() {
    try {
        demoVector();
        demoSquareMatrix();
        demoTriangularMatrix();
        demoSparseMatrix();
        
        std::cout << "\nAll demonstrations completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
