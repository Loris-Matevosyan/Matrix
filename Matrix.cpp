#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Matrix::Matrix () : Matrix (4, 4) {
}

Matrix::Matrix (int row, int column) : row{row}, column{column} {
    ptr_matrix = new int *[row];
    for (int i = 0; i < row; ++i)
        ptr_matrix[i] = new int[column];
    std::cout << "\nConstructor have been called for " << row << " rows matrix" << std::endl;
}


void Matrix::init_matrix() {
    srand(time(NULL));
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            ptr_matrix[i][j] = rand()%30 + 11;
    display_matrix();
}

void Matrix::display_matrix () {
    std::cout << std::endl;
    std::cout << " ___";
    for (int i = 0; i < (column * 2 - 3); ++i)
        std::cout << " ";
    std::cout << "MATRIX";
    for (int i = 0; i < (column * 2 - 3); ++i)
        std::cout << " ";
    std::cout << "___" << std::endl;
    std::cout << "| ";
    for (int i = 0; i < (column * 2) + (column * 2); ++i) 
        std::cout << " ";
    std::cout << "     |" << std::endl;
    for (int i = 0; i < row; ++i) {
        std::cout << "|    ";
        for (int j = 0; j < column; ++j)
           std::cout << ptr_matrix[i][j] << "  ";
        std::cout << "  |" << std::endl;
    }
    std::cout << "|___";
    for (int i = 0; i < (column * 2) + (column * 2); ++i)
        std::cout << " ";
    std::cout << "___|" << std::endl;
}

void Matrix::swap_rows() {
    int row_1{}, row_2{}, temp;
    std::cout << "\nIn matrix rows are from 1 to " << row << std::endl;
    std::cout << "Which two rows do you want to swap" << std::endl;
    std::cout << "Enter first row: ";
    std::cin >> row_1;
    std::cout << "Enter second row: ";
    std::cin >> row_2;
    for (int i = 0; i < column; ++i) {
        temp = ptr_matrix[row_1 - 1][i];
        ptr_matrix[row_1 - 1][i] = ptr_matrix[row_2 - 1][i];
        ptr_matrix[row_2 - 1][i] = temp;
    }
    std::cout << "Matrix after swap " << row_1 << " and " << row_2 << " rows:" << std::endl;
    display_matrix();
}

void Matrix::swap_columns() {
    int column_1{}, column_2{}, temp{};
    std::cout << "\nIn matrix columns are from 1 to " << column << std::endl;
    std::cout << "Which two columns do you want to swap" << std::endl;
    std::cout << "Enter first column: ";
    std::cin >> column_1;
    std::cout << "Enter second column: ";
    std::cin >> column_2;
    for (int i = 0; i < row; ++i) {
        temp = ptr_matrix[i][column_1 - 1];
        ptr_matrix[i][column_1 - 1] = ptr_matrix[i][column_2 - 1];
        ptr_matrix[i][column_2 - 1] = temp;
    }  
    std::cout << "Matrix after swap " << column_1 << " and " << column_2 << " columns:" << std::endl;
    display_matrix();
}


Matrix::~Matrix() {
   for (int i = 0; i < row; ++i)
       delete ptr_matrix[i];
   delete [] ptr_matrix;
   std::cout << "\nDestuctor have been called for " << row << " rows matrix" << std::endl;  
}

