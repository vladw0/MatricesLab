#include "../include/square_matrix.h"

namespace Matrix {

template<typename T>
SquareMatrix<T>::SquareMatrix() : size_(0) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(size_t size) : size_(size), data_(size, std::vector<T>(size)) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(size_t size, const T& value) : size_(size), data_(size, std::vector<T>(size, value)) {}

template<typename T>
SquareMatrix<T>::SquareMatrix(std::initializer_list<std::initializer_list<T>> init) {
    size_ = init.size();
    data_.resize(size_);
    
    auto it = init.begin();
    for (size_t i = 0; i < size_; ++i, ++it) {
        if (it->size() != size_) {
            throw std::invalid_argument("Square matrix must have same number of rows and columns");
        }
        data_[i] = std::vector<T>(it->begin(), it->end());
    }
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Matrix sizes don't match for addition");
    }
    
    SquareMatrix result(size_);
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            result.data_[i][j] = data_[i][j] + other.data_[i][j];
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator-(const SquareMatrix& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Matrix sizes don't match for subtraction");
    }
    
    SquareMatrix result(size_);
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            result.data_[i][j] = data_[i][j] - other.data_[i][j];
        }
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(const SquareMatrix& other) const {
    if (size_ != other.size_) {
        throw std::invalid_argument("Matrix sizes don't match for multiplication");
    }
    
    SquareMatrix result(size_);
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            T sum = T();
            for (size_t k = 0; k < size_; ++k) {
                sum += data_[i][k] * other.data_[k][j];
            }
            result.data_[i][j] = sum;
        }
    }
    return result;
}

template<typename T>
bool SquareMatrix<T>::operator==(const SquareMatrix& other) const {
    if (size_ != other.size_) return false;
    
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            if (data_[i][j] != other.data_[i][j]) return false;
        }
    }
    return true;
}

template<typename T>
bool SquareMatrix<T>::operator!=(const SquareMatrix& other) const {
    return !(*this == other);
}

template<typename T>
T& SquareMatrix<T>::operator()(size_t row, size_t col) {
    if (row >= size_ || col >= size_) throw std::out_of_range("Matrix index out of range");
    return data_[row][col];
}

template<typename T>
const T& SquareMatrix<T>::operator()(size_t row, size_t col) const {
    if (row >= size_ || col >= size_) throw std::out_of_range("Matrix index out of range");
    return data_[row][col];
}

template<typename T>
size_t SquareMatrix<T>::size() const {
    return size_;
}

template<typename T>
bool SquareMatrix<T>::isEmpty() const {
    return size_ == 0;
}

template<typename T>
bool SquareMatrix<T>::isFull() const {
    return true;
}

template<typename T>
void SquareMatrix<T>::applyLambda(const std::function<void(T&)>& func) {
    for (auto& row : data_) {
        for (auto& element : row) {
            func(element);
        }
    }
}

template<typename T>
T SquareMatrix<T>::trace() const {
    if (isEmpty()) return T();
    
    T result = T();
    for (size_t i = 0; i < size_; ++i) {
        result += data_[i][i];
    }
    return result;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::transpose() const {
    SquareMatrix result(size_);
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            result.data_[i][j] = data_[j][i];
        }
    }
    return result;
}

template<typename T>
void SquareMatrix<T>::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);
    
    file << size_ << "\n";
    for (const auto& row : data_) {
        for (size_t j = 0; j < row.size(); ++j) {
            file << row[j];
            if (j < row.size() - 1) file << " ";
        }
        file << "\n";
    }
}

template<typename T>
void SquareMatrix<T>::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);
    
    file >> size_;
    data_.resize(size_, std::vector<T>(size_));
    for (auto& row : data_) {
        for (auto& element : row) {
            file >> element;
        }
    }
}

// Явные инстанцирования
template class SquareMatrix<int>;
template class SquareMatrix<double>;
template class SquareMatrix<float>;

} // namespace Matrix