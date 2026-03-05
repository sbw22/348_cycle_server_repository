#include <stdio.h>
#define SIZE 5

int print_matrix(int matrix[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int add_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    printf("\nResult of Matrix Addition:\n");
    print_matrix(result);
    return 0;
}

int multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result[i][j] = 0;
            for(int k = 0; k < SIZE; k++){
                // switched the order of m1 and m2 to get the correct result
                // We want to multiply m2's column by m1's row, so we need to access m1[i][k] and m2[k][j] (I think I had it backwards before)
                // result[i][j] += m1[i][k] * m2[k][j];
                result[i][j] += m2[i][k] * m1[k][j];
            }
        }
    }
    printf("\nResult of Matrix Multiplication:\n");
    print_matrix(result);
    return 0;
}

int transpose_matrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            result[j][i] = matrix[i][j];
        }
    }
    printf("\nResult of Matrix Transposition:\n");
    print_matrix(result);
    return 0;
}

int main(){
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int add_result[SIZE][SIZE];
    int multiply_result[SIZE][SIZE];
    int transpose_result[SIZE][SIZE];

    add_matrices(m1, m2, add_result); 
    multiply_matrices(m1, m2, multiply_result);
    transpose_matrix(m1, transpose_result);
    return 0;
}