/*
    Autora: Andressa Von Ahnt
*/

#include <stdio.h>
#include <stdlib.h>

/*
====================
Generate

  Creates Pascal's Triangle with numRows rows.
====================
*/
int** generate( int numRows, int* returnSize, int** returnColumnSizes ) {
    int **arrayRows;

    if ( ( arrayRows = (int **)malloc( numRows * sizeof( int * ) ) ) == NULL ){
        printf( "Error allocating memory" );
        exit( 1 );
    }

    if ( ( *returnColumnSizes = (int *)malloc( numRows * sizeof( int ) ) ) == NULL ){
        printf( "Error allocating memory" );
        exit( 1 );
    }

    for ( int i = 0; i < numRows; i++ ){
        if ( ( arrayRows[i] = (int *)malloc( sizeof( int ) * ( i + 1 ) ) ) == NULL ){
            printf( "Error allocating memory" );
            exit( 1 );
        }

        arrayRows[i][0] = 1;
        arrayRows[i][i] = 1;

        for ( int j = 1; j < i; j++ )
            arrayRows[i][j] = arrayRows[i - 1][j - 1] + arrayRows[i - 1][j];

        ( *returnColumnSizes )[i] = i + 1;
    }

    *returnSize = numRows;
    return arrayRows;
}


int main() {
    int numRows = 5;         
    int returnSize;         
    int *returnColumnSizes; 
    int **pascalsTriangle = generate(numRows, &returnSize, &returnColumnSizes);

    printf("Pascal's Triangle:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", pascalsTriangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < returnSize; i++) {
        free(pascalsTriangle[i]); 
    }
    free(pascalsTriangle);        
    free(returnColumnSizes);      

    return 0;
}