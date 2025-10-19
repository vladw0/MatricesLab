#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <stdexcept>

namespace Matrix {

template<typename T>
class Vector {
private:
    std::vector<T> data_;

public:
    // Конструкторы
    Vector();
    Vector(size_t size);
    Vector(size_t size, const T& value);
    Vector(std::initializer_list<T> init);
    
    // Копирование и перемещение
    Vector(const Vector& other) = default;
    Vector(Vector&& other) = default;
    Vector& operator=(const Vector& other) = default;
    Vector& operator=(Vector&& other) = default;
    
    // Доступ к элементам
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    // Размер и емкость
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    
    // Модификация
    void pushBack(const T& value);
    void pushFront(const T& value);
    
    // Лямбда-выражение
    void applyLambda(const std::function<void(T&)>& func);
    
    // Операторы сравнения
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    
    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[ ";
        for (size_t i = 0; i < vec.data_.size(); ++i) {
            os << vec.data_[i];
            if (i < vec.data_.size() - 1) os << " ";
        }
        os << " ]";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        for (size_t i = 0; i < vec.data_.size(); ++i) {
            is >> vec.data_[i];
        }
        return is;
    }
    
    // Файловые операции
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

} // namespace Matrix