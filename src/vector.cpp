#include "../include/vector.h"

namespace Matrix {

template<typename T>
Vector<T>::Vector() : data_() {}

template<typename T>
Vector<T>::Vector(size_t size) : data_(size) {}

template<typename T>
Vector<T>::Vector(size_t size, const T& value) : data_(size, value) {}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> init) : data_(init) {}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= data_.size()) throw std::out_of_range("Vector index out of range");
    return data_[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= data_.size()) throw std::out_of_range("Vector index out of range");
    return data_[index];
}

template<typename T>
size_t Vector<T>::size() const {
    return data_.size();
}

template<typename T>
bool Vector<T>::isEmpty() const {
    return data_.empty();
}

template<typename T>
bool Vector<T>::isFull() const {
    return false;
}

template<typename T>
void Vector<T>::pushBack(const T& value) {
    data_.push_back(value);
}

template<typename T>
void Vector<T>::pushFront(const T& value) {
    data_.insert(data_.begin(), value);
}

template<typename T>
void Vector<T>::applyLambda(const std::function<void(T&)>& func) {
    for (auto& element : data_) {
        func(element);
    }
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const {
    return data_ == other.data_;
}

template<typename T>
bool Vector<T>::operator!=(const Vector& other) const {
    return data_ != other.data_;
}

template<typename T>
void Vector<T>::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);
    
    file << data_.size() << "\n";
    for (const auto& element : data_) {
        file << element << " ";
    }
    file << "\n";
}

template<typename T>
void Vector<T>::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);
    
    size_t size;
    file >> size;
    data_.resize(size);
    for (size_t i = 0; i < size; ++i) {
        file >> data_[i];
    }
}

// Явные инстанцирования для компиляции
template class Vector<int>;
template class Vector<double>;
template class Vector<float>;

} // namespace Matrix