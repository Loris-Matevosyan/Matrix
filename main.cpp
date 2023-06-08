#include "Matrix.h"
#include <iostream>
#include <vector>

void user_input(int &, int &);                     //User input prototype

int main () {
//    
     int row{}, column{};
     user_input(row, column);
     Matrix matrix(row, column);
     matrix.init_matrix();
     matrix.swap_rows();
     matrix.swap_columns();
 
return 0;   
}

void user_input(int &row, int &column) {
     std::cout << "Enter number of rows in matrix: ";
     std::cin >> row;
     std::cout << "Enter number of columns in matrix: ";
     std::cin >> column;
}
