#include <stdio.h>
#include <stdin.h>

int _size = 9;
int true = 1;
int false = 0;


int main(){
    int matrix[_size][_size] = {0};

}


int * solveSudoku(int matrix[][_size]){
    int filler = 0;
    while(1){
        int row = 0, column = 0;
        //first trying to fill the columns with the correct numbers
        for(; column < _size; column++){
            //checking if the column has no number in it
            if(matrix[row][column] == 0){
                
                if(!(checkColumn(fillVectorByColumn(matrix, column), filler)) && !(checkRow(fillVectorByRow(matrix, row), filler)) && ){
                    
                }
            }

        }
    }
}

//fill a vector with the numbers in a given colmumn of a matrix and return it
int * fillVectorByColumn(int matrix[][_size], int column){
    int vector[_size], i;

    for(i=0 ; i< _size; i++){
        vector[i] = matrix[i][column];
    }

    return vector;
}


//fill a vector with the numbers in a given row of a matrix and return it
int * fillVectorByRow(int matrix[][_size], int row){
    int vector[_size], i;

    for(i=0; i<_size; i++){
        vector[i] = matrix[row][i];
    }

    return vector;
}
//return TRUE if it finds an equal number in the selected row
int checkRow(int row[], int num){
    int i;

    for(i = 0;i < _size; i++ ){
        if(row[i] == num){
            return true;
        }
    }    
    return false;
}


//return TRUE if it finds an equal number in the selected column
int checkColumn(int column[], int num){
    int i;

    for(i=0; i < _size; i++){
        if(column[i] == num){
            return  true;
        }        
    }
    return false;
}

//return TRUE if it finds an equal number in the selected square
int checkSquare(int square[][(_size-1)/2], int num){
    int c,r;

    for(c=0; c <(_size/2); c++){
        for(r=0; r<(_size/2);r++){
            if(square[c][r] ==  num){
                return true;
            }
        }
    }
    return false;
}