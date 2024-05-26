#include <iostream>

class Matrix {
private:
    int mat[4][3];
    int rows = 4;
    int cols = 3;

public:
    Matrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    void setElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            mat[row][col] = value;
        }
    }

    int getElement(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return mat[row][col];
        }
        return 0;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = this->mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = this->mat[i][j] * other.mat[i][j];
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat1;
    Matrix mat2;

    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);
    mat1.setElement(2, 0, 7);
    mat1.setElement(2, 1, 8);
    mat1.setElement(2, 2, 9);
    mat1.setElement(3, 0, 10);
    mat1.setElement(3, 1, 11);
    mat1.setElement(3, 2, 12);

    mat2.setElement(0, 0, 2);
    mat2.setElement(0, 1, 3);
    mat2.setElement(0, 2, 4);
    mat2.setElement(1, 0, 5);
    mat2.setElement(1, 1, 6);
    mat2.setElement(1, 2, 7);
    mat2.setElement(2, 0, 8);
    mat2.setElement(2, 1, 9);
    mat2.setElement(2, 2, 10);
    mat2.setElement(3, 0, 11);
    mat2.setElement(3, 1, 12);
    mat2.setElement(3, 2, 13);

    Matrix sum = mat1 + mat2;
    std::cout << "Summa:" << std::endl;
    sum.display();

    Matrix difference = mat1 - mat2;
    std::cout << "Riznicya:" << std::endl;
    difference.display();

    Matrix product = mat1 * mat2;
    std::cout << "Dobutok:" << std::endl;
    product.display();

    return 0;
}
