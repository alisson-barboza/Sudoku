#include <stdio.h>
#include <stdin.h>

int _size = 9;
int true = 1;
int false = 0;


int main(){
    int matrix[_size][_size] = {0};

}


int * solveSudoku(int matrix[][_size], int row, int column){
    int filler = 0;
    int i = 0;
    int rAux, cAux;

    if(matrix[row][column] != 0){
        if(row == (_size - 1) && column == (_size - 1)){
            return matrix;            
        }

        if(column < (_size - 1)){
            column++;

        }
        else{
            if(row < (_size - 1)){
                row++;
                column = 0;
            }
        }

        return solveSudoku(matrix, row, column);
    }

    if(matrix[row][column] == 0){
        while(i < _size - 1){
            if(!checkColumn(fillVectorByColumn(matrix, column), filler) && !checkRow(fillVectorByRow(matrix, row), filler) 
            && !checkSquare(fillSquare(matrix, row, column))){
                matrix[row][column] = filler;
            }else{
                rAux = row + 1;
            }

            i++;
        }

    }

}
//fill a matrix smaller than the original with the numbers in a given "square"
int * fillSquare(int matrix[][_size], int row, int column){
    int newMatrix[_size/2][_size/2] = {0};
    int r, c, stopC, stopR;
    int rAux, cAux;

    switch(row){
        case r<2:
        r = 0;  
        break;
        case r<5:
        r = 3;
        break;
        case r<8:
        r = 6;
        break;        
    }

    switch(column){
        case c<2:
        c = 0;  
        break;
        case c<5:
        c = 3;
        break;
        case c<8:
        c = 6;
        break;
    }

    stopR = r + 3;
    stopC = c + 3;

    for(cAux = 0;c<stopC; c++){
        for(rAux = 0;r<stopR;r++){
            newMatrix[cAux][rAux] = matrix[c][r]
            rAux++;
        }
        cAux++;
    }
    return newMatrix;
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