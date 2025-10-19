#include "../include/triangular_matrix.h"

namespace Matrix {

template<typename T>
TriangularMatrix<T>::TriangularMatrix() : size_(0), is_upper_(true) {}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(size_t size, bool is_upper) 
    : size_(size), is_upper_(is_upper), data_(size * (size + 1) / 2) {}

template<typename T>
TriangularMatrix<T>::TriangularMatrix(size_t size, const T& value, bool is_upper)
    : size_(size), is_upper_(is_upper), data_(size * (size + 1) / 2, value) {}

template<typename T>
size_t TriangularMatrix<T>::size() const {
    return size_;
}

template<typename T>
bool TriangularMatrix<T>::isEmpty() const {
    return size_ == 0;
}

template<typename T>
bool TriangularMatrix<T>::isFull() const {
    return true;
}

template<typename T>
bool TriangularMatrix<T>::isUpper() const {
    return is_upper_;
}

// Остальные методы будут аналогично реализованы

// Явные инстанцирования
template class TriangularMatrix<int>;
template class TriangularMatrix<double>;
template class TriangularMatrix<float>;

} // namespace Matrix