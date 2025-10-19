#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <stdexcept>

namespace Matrix {

template<typename T>
class SparseMatrix {
private:
    std::map<std::pair<size_t, size_t>, T> data_;
    size_t rows_, cols_;

public:
    // Конструкторы
    SparseMatrix();
    SparseMatrix(size_t rows, size_t cols);
    
    // Копирование и перемещение
    SparseMatrix(const SparseMatrix& other) = default;
    SparseMatrix(SparseMatrix&& other) = default;
    SparseMatrix& operator=(const SparseMatrix& other) = default;
    SparseMatrix& operator=(SparseMatrix&& other) = default;
    
    // Арифметические операции
    SparseMatrix operator+(const SparseMatrix& other) const;
    SparseMatrix operator-(const SparseMatrix& other) const;
    
    // Операторы сравнения
    bool operator==(const SparseMatrix& other) const;
    bool operator!=(const SparseMatrix& other) const;
    
    // Доступ к элементам
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;
    
    // Размеры
    size_t rows() const;
    size_t cols() const;
    bool isEmpty() const;
    bool isFull() const;
    size_t nonZeroCount() const;
    
    // Лямбда-выражение
    void applyLambda(const std::function<void(T&)>& func);
    
    // Специальные методы для разреженных матриц
    void setZeroThreshold(T threshold);
    
    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat);
    
    // Файловые операции
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

} // namespace Matrix