#include "../include/sparse_matrix.h"

namespace Matrix {

template<typename T>
SparseMatrix<T>::SparseMatrix() : rows_(0), cols_(0) {}

template<typename T>
SparseMatrix<T>::SparseMatrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {}

template<typename T>
size_t SparseMatrix<T>::rows() const {
    return rows_;
}

template<typename T>
size_t SparseMatrix<T>::cols() const {
    return cols_;
}

template<typename T>
bool SparseMatrix<T>::isEmpty() const {
    return rows_ == 0 || cols_ == 0;
}

template<typename T>
bool SparseMatrix<T>::isFull() const {
    return false;
}

template<typename T>
size_t SparseMatrix<T>::nonZeroCount() const {
    return data_.size();
}

// Остальные методы будут аналогично реализованы

// Явные инстанцирования
template class SparseMatrix<int>;
template class SparseMatrix<double>;
template class SparseMatrix<float>;

} // namespace Matrix