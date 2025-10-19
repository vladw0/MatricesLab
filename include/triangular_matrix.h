#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <stdexcept>

namespace Matrix {

template<typename T>
class TriangularMatrix {
private:
    std::vector<T> data_; // Храним только треугольные элементы
    size_t size_;
    bool is_upper_;

public:
    // Конструкторы
    TriangularMatrix();
    TriangularMatrix(size_t size, bool is_upper = true);
    TriangularMatrix(size_t size, const T& value, bool is_upper = true);
    
    // Копирование и перемещение
    TriangularMatrix(const TriangularMatrix& other) = default;
    TriangularMatrix(TriangularMatrix&& other) = default;
    TriangularMatrix& operator=(const TriangularMatrix& other) = default;
    TriangularMatrix& operator=(TriangularMatrix&& other) = default;
    
    // Арифметические операции
    TriangularMatrix operator+(const TriangularMatrix& other) const;
    TriangularMatrix operator-(const TriangularMatrix& other) const;
    
    // Операторы сравнения
    bool operator==(const TriangularMatrix& other) const;
    bool operator!=(const TriangularMatrix& other) const;
    
    // Доступ к элементам
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;
    
    // Размер
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    bool isUpper() const;
    
    // Лямбда-выражение
    void applyLambda(const std::function<void(T&)>& func);
    
    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const TriangularMatrix& mat);
    
    // Файловые операции
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

} // namespace Matrix