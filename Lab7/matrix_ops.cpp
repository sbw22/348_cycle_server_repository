#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int SIZE = 4; // Global variable for matrix size

class Matrix {
    private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

    public:

    // 1. Read values from stdin into a matrix
    void readFromTxt(int arr[4][4]) {
        for (int i = 0; i < SIZE*SIZE; ++i) {
         data[i/SIZE][i%SIZE] = arr[i/SIZE][i%SIZE]; // Read into data array
    }
    }

    // 2. Display a matrix
    void display(){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const{
        Matrix sum;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                sum.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return sum;
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const{
        // For matrix multiplication, we need to compute the dot product of rows and columns
        Matrix product;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                product.data[i][j] = 0; // Initialize the product element
                for (int k = 0; k < SIZE; ++k) {
                    product.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return product;
    }

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const{
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += data[i][i]; // Add the main diagonal element
        }
        return sum;
    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2){
        // Implement a function that accepts a matrix and two-row indices. If both indices are valid, swap the rows and display the resulting matrix.
        if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
            for (int j = 0; j < SIZE; ++j) {
                int temp = data[row1][j];
                data[row1][j] = data[row2][j];
                data[row2][j] = temp;
            }
        }
    }
};

int main() {

    string filePath = "inputs.txt"; // Path to the input file
    // Open the file using ifstream
    ifstream file(filePath);
    // confirm file opening
    if (!file.is_open()) {
        // print error message and return
        cerr << "Failed to open file: " << filePath << endl;
        return 0; 
    }

    int arr1[SIZE][SIZE]; // Array to hold all the rows of the first matrix
    int arr2[SIZE][SIZE]; // Array to hold all the rows of the second matrix

    // input dimensions are 4x8, so we read 4 rows for the first matrix and 4 rows for the second matrix
    for (int i = 0; i < SIZE*SIZE; ++i) {
         file >> arr1[i/SIZE][i%SIZE]; // Read into the first matrix
    }
    for (int i = 0; i < SIZE*SIZE; ++i) {
         file >> arr2[i/SIZE][i%SIZE]; // Read into the second matrix
    }
    file.close();

    Matrix mat1, mat2;
    mat1.readFromTxt(arr1); // Read the first matrix from the array
    mat2.readFromTxt(arr2); // Read the second matrix from the array

    
    mat1.display();
    mat2.display();
 

    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
