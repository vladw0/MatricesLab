cmake_minimum_required(VERSION 3.10)
project(MatricesLab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основное приложение
add_executable(matrices_lab 
    src/main.cpp
    src/vector.cpp
    src/square_matrix.cpp
    src/triangular_matrix.cpp
    src/sparse_matrix.cpp
)

# Настройки компиляции для основного приложения
target_include_directories(matrices_lab PUBLIC ${CMAKE_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(matrices_lab PRIVATE /W4)
else()
    target_compile_options(matrices_lab PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Тесты
enable_testing()

# ВАРИАНТ 1: Использование системного GTest (рекомендуется)
find_package(GTest REQUIRED)

# Исполняемый файл для тестов
add_executable(matrix_tests
    tests/testmain.cpp
    tests/test-vector.cpp
    tests/test-squarematrix.cpp
    tests/test-triangularmatrix.cpp
    tests/test-sparsematrix.cpp
    src/vector.cpp
    src/square_matrix.cpp
    src/triangular_matrix.cpp
    src/sparse_matrix.cpp
)

# Настройки для тестов
target_include_directories(matrix_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(matrix_tests GTest::gtest GTest::gtest_main)

if(MSVC)
    target_compile_options(matrix_tests PRIVATE /W4)
else()
    target_compile_options(matrix_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Добавляем тесты в CTest
add_test(NAME VectorTests COMMAND matrix_tests --gtest_filter="VectorTest*")
add_test(NAME SquareMatrixTests COMMAND matrix_tests --gtest_filter="SquareMatrixTest*")
add_test(NAME TriangularMatrixTests COMMAND matrix_tests --gtest_filter="TriangularMatrixTest*")
add_test(NAME SparseMatrixTests COMMAND matrix_tests --gtest_filter="SparseMatrixTest*")
add_test(NAME AllTests COMMAND matrix_tests)