#include <stdio.h>
/*
eg:
input  matrix is:
| 1 2 3 |
| 4 5 6 |
| 7 8 9 |
matrixT(transposition) is:
| 1 4 7 |
| 2 5 8 |
| 3 6 9 |
matrix diagonal(main is 1) is:
| 0 0 1 |
| 0 1 0 |
| 1 0 0 |
so rotate 90 is 
| 1 4 7 |   | 0 0 1 |   | 7 4 1 |
| 2 5 8 | X | 0 1 0 | = | 8 5 2 |
| 3 6 9 |   | 1 0 0 |   | 9 6 3 |
*/

int row = 0;
int column  = 0; 

void printfMatrix(int** matrixData)
{
    for(int i = 0;i < row;i++)     
    {   
        for(int j = 0;j<column;j++)
        {    
            printf("%2d ",matrixData[i][j]);
        }
        printf("\n");
    } 
}

int ** initMatrixArray()
{
    int **matrix = NULL;
    matrix = new int* [row];
    for(int i = 0;i < row;i++)
    {
	    matrix[i] = new int [column];
    }
    for(int i = 0;i < row;i++) 
    {
    	for(int j = 0;j<column;j++)
    	{
    	    matrix[i][j]=0;
    	}
    } 
    return matrix;
}
void unintMatrixArray(int ** matrix)
{
    for(int i = 0;i < row;i++)
    {
        delete [] (matrix)[i];
    }
    delete [] matrix;
}
void getMatrix(int **baseMatrix)
{
    printf("\n================input matrix  ====================\n"); 
    for(int i = 0;i < row;i++) 
    {
    	for(int j = 0;j<column;j++)
    	{
    	    scanf("%d",&baseMatrix[i][j]);
    	}
    } 
    printf("\n================matrix is ====================\n"); 
    printfMatrix(baseMatrix);
}
int ** matrixTransposition(int ** baseMatrix)
{
    int** matrixT=initMatrixArray();
    for(int i = 0;i < row;i++)     
    {   
        for(int j = 0;j<column;j++)
        {    
            (matrixT[i][j]) = baseMatrix[j][i];
        }
    }
    printfMatrix(matrixT);
    return (matrixT);
}
void matrixTimes(int ** baseMatrix1,int ** baseMatrix2)
{
    printf("baseMatrix1 :\n\n");
    printfMatrix(baseMatrix1);
    printf("baseMatrix2 :\n\n");
    printfMatrix(baseMatrix2);
    int **matrixTimes=initMatrixArray();
    printf("baseMatrix1 times baseMatrix2\n\n");
    for(int k = 0;k < row;k++)     
    {   
        for(int l = 0;l<column;l++)
        {    
            for(int j = 0;j<column;j++)
            {    
                //printf("\n================baseMatrix1[%d][%d] %d  baseMatrix2[%d][%d] %d====================\n",k,j,baseMatrix1[k][j],j,l,baseMatrix2[j][l]); 
                matrixTimes[k][l] += baseMatrix1[k][j]*baseMatrix2[j][l];
                //printf("\n================matrixTimes[%d][%d] %d====================\n",k,l,matrixTimes[k][l]); 
            }
        }
    }
   printfMatrix(matrixTimes);
   unintMatrixArray(matrixTimes);
}
void matrixDiagonal(int ** baseMatrix)
{
    for(int i = 0;i < row;i++)     
    {   
        for(int j = 0;j < column;j++)
        {   
            if(i + j == column-1)
            {
                baseMatrix[i][j] = 1;
            }
            else
            {
                baseMatrix[i][j] = 0;
            }
        }
    }
    printf("\n diagonal matrix:\n"); 
    printfMatrix(baseMatrix);
    printf("\n\n");
}
void matrixRotate(int ** baseMatrix)
{
    int** matrixD=initMatrixArray();
    matrixDiagonal(matrixD);
    int** matrixT=matrixTransposition(baseMatrix);
    matrixTimes(matrixT,matrixD);
    unintMatrixArray(matrixD);
    unintMatrixArray(matrixT);
}
int main(int argc,char* argv[])
{
    printf("it is my test!!! \n");
    
    scanf("%d",&row);
    column = row;
    printf("matrix's  is %d X %d !!! \n",row,column);
    int **baseMatrix=initMatrixArray();
    getMatrix(baseMatrix);

    printf("\n================matrix T ====================\n"); 
    int** matrixT = matrixTransposition(baseMatrix);
    unintMatrixArray(matrixT);
    printf("\n================matrix times matrix ====================\n"); 
    matrixTimes(baseMatrix,baseMatrix);
    printf("\n================matrix rotate ====================\n");
    matrixRotate(baseMatrix);
    unintMatrixArray(baseMatrix);
    return 0;
}
