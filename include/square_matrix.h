#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <stdexcept>

namespace Matrix {

template<typename T>
class SquareMatrix {
private:
    std::vector<std::vector<T>> data_;
    size_t size_;

public:
    // Конструкторы
    SquareMatrix();
    explicit SquareMatrix(size_t size);
    SquareMatrix(size_t size, const T& value);
    SquareMatrix(std::initializer_list<std::initializer_list<T>> init);
    
    // Копирование и перемещение
    SquareMatrix(const SquareMatrix& other) = default;
    SquareMatrix(SquareMatrix&& other) = default;
    SquareMatrix& operator=(const SquareMatrix& other) = default;
    SquareMatrix& operator=(SquareMatrix&& other) = default;
    
    // Арифметические операции
    SquareMatrix operator+(const SquareMatrix& other) const;
    SquareMatrix operator-(const SquareMatrix& other) const;
    SquareMatrix operator*(const SquareMatrix& other) const;
    
    // Операторы сравнения
    bool operator==(const SquareMatrix& other) const;
    bool operator!=(const SquareMatrix& other) const;
    
    // Доступ к элементам
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;
    
    // Размер
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    
    // Лямбда-выражение
    void applyLambda(const std::function<void(T&)>& func);
    
    // Специальные методы для квадратных матриц
    T trace() const; // След матрицы
    SquareMatrix transpose() const;
    
    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& mat) {
        for (size_t i = 0; i < mat.size_; ++i) {
            for (size_t j = 0; j < mat.size_; ++j) {
                os << mat.data_[i][j];
                if (j < mat.size_ - 1) os << " ";
            }
            os << "\n";
        }
        return os;
    }
    
    // Файловые операции
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

} // namespace Matrix