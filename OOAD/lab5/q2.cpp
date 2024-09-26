#include <bits/stdc++.h>
using namespace std;
class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
 
    Matrix(int rows, int cols, int initValue = 0) : rows(rows), cols(cols) {
        
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = rand() % 10;
        }
    }


    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }


    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout<< "Error: Matrix dimensions must be the same for addition.\n";
            exit(1);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

  
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrix dimensions must be the same for subtraction.\n";
            exit(1);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Error: Number of columns in first matrix must match number of rows in second matrix for multiplication.\n";
            exit(1);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < cols; ++i)
            for (int j = 0; j < rows; ++j)
                result.data[i][j] = data[j][i];
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    srand(time(NULL));
    Matrix mat1(2, 3, 1); 
    Matrix mat2(2, 3, 2); 

    cout << "Matrix 1:\n";
    mat1.display();
    cout << "Matrix 2:\n";
    mat2.display();

    cout << "Matrix 1 + Matrix 2:\n";
    Matrix resultAdd = mat1 + mat2;
    resultAdd.display();

    cout << "Matrix 1 - Matrix 2:\n";
    Matrix resultSub = mat1 - mat2;
    resultSub.display();

    
    Matrix mat3(3, 2, 3); 
    cout << "Matrix 1 * Matrix 3:\n";
    Matrix resultMul = mat1 * mat3;
    resultMul.display();

  
    cout << "Transpose of Matrix 1:\n";
    Matrix resultTrans = mat1.transpose();
    resultTrans.display();

    return 0;
}