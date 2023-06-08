#ifndef _MATRIX_
#define _MATRIX_


class Matrix {
private:
    int row{}, column{};
    int **ptr_matrix{nullptr};
public:
    void init_matrix();                                   //  Matrix initialization
    void display_matrix();                               //  Display matrix
    void swap_rows();                                   //  Rows swapping
    void swap_columns();                               //  Columns swapping
    Matrix();                                         //  Delegating constractor
    Matrix(int row, int column);                     //  Overloaded constructor
    ~Matrix();                                      //  Destructor

};

#endif // _MATRIX_
