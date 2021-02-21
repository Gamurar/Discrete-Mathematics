#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printMatrix(int* matrix, int rows, int cols, int vertices);

int* allocateMatrix(int rows, int cols);
void reallocateMatrix(int* matrix, int rows, int cols);
_Bool lastRowsAreSame(int* matrix, int rows, int cols);
void fillLastVector(int* matrix, int rows, int cols);

int main()
{
    printf("\n == Bellman-Kalaba algorithm to find minimum path == \n");

    int rows = 0;
    int cols = 0;
    printf("Please, enter number of rows of the adjacency matrix: ");
    scanf("%d", &rows);
    printf("Please, enter number of collumns of the adjacency matrix: ");
    scanf("%d", &cols);
    printf("Okay, thanks! Creating the matrix...\n");
    int vertices = rows;
    // 2 more rows for vectors
    rows += 2;
    int* matrix = allocateMatrix(rows, cols);

    printf("The matrix has been created!\n");
    printf("Please, fill up the matrix. For infinity value, write -1:\n");
    int value = -10;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &value);
            if (value == -1)
            {
                matrix[i*cols + j] = INT_MAX;
            }
            else
            {
                matrix[i*cols + j] = value;
            }
        }
    }
    printf("Great! Matrix has been filled. Here is your adjacency matrix:\n");
    printMatrix(matrix, vertices, cols, vertices);
    printf("\nNow let's run the Bellman-Kalaba algorithm to find a minimum path...\n");
    printf("Fill the first vector:\n");
    for (int i = 0; i < vertices; i++)
    {
        matrix[cols*vertices + i] = matrix[i * vertices + (vertices-1)];
    }
    printMatrix(matrix, vertices + 1, cols, vertices);

    printf("\nFill the second vector:\n");
    fillLastVector(matrix, rows, cols);
    printMatrix(matrix, rows, cols, vertices);

    printf("\nFill other vectors until last 2 vectors are same...\n");
    while (!lastRowsAreSame(matrix, rows, cols))
    {
        rows++;
        reallocateMatrix(matrix, rows, cols);
        fillLastVector(matrix, rows, cols);
    }

    printf("\nThe final matrix:\n");
    printMatrix(matrix, rows, cols, vertices);

    printf("\nMinimum path length between vertex 1 and %d is %d\n", vertices, matrix[cols*(rows-1)]);
    printf("\nCalculating concrete minimum path...\n");
    int* minPath = calloc(vertices, sizeof(int));
    int minPathCounter = 0;
    minPath[minPathCounter] = 1;
    int diff = -1;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j != i)
            {
                diff = matrix[(rows-1)*cols + i] - matrix[(rows-1)*cols + j];
                if (matrix[i*cols + j] == diff)
                {
                    printf("P(%d%d) = V%d - V%d  |  ", i+1, j+1, i+1, j+1);
                    printf("%d = %d - %d\n", matrix[i*cols + j], matrix[(rows-1)*cols + i], matrix[(rows-1)*cols + j]);
                    if (minPath[minPathCounter] == i+1)
                    {
                        minPath[++minPathCounter] = j + 1;
                    }
                }
            }
        }
    }

    printf("\nConcrete minimum path is:\n");
    for (int i = 0; i < minPathCounter; i++)
    {
        printf("%d -> ", minPath[i]);
    }
    printf("%d", minPath[minPathCounter]);



    free(matrix);
    matrix = NULL;
    free(minPath);
    minPath = NULL;

    return 0;
}

void printMatrix(int* matrix, int rows, int cols, int vertices)
{
    printf("    ");
    for (int i = 0; i < cols; i++)
    {
        printf("  %d  ", i + 1);
    }
    printf("\n  +");
    for (int i = 0; i < cols; i++)
    {
        printf("-----", i + 1);
    }
    printf("\n");

    int vCounter = 0;
    for (int i = 0; i < rows; i++)
    {
        if (i >= vertices)
        {
            printf("V%d| ", vCounter++);
        }
        else if (i > 8)
        {
            printf("%d| ", i + 1);
        }
        else
        {
            printf("%d | ", i + 1);
        }

        for (int j = 0; j < cols; j++)
        {
            if (matrix[i*cols + j] == INT_MAX) 
            {
                printf(" oxo ");
            }
            else if (matrix[i*cols + j] > 9)
            {
                printf(" %d  ",matrix[i*cols + j]);
            }
            else
            {
                printf("  %d  ",matrix[i*cols + j]);
            }
            
        }
        printf("\n");
    }
}

int* allocateMatrix(int rows, int cols)
{
    return calloc(rows * cols, sizeof(int));
}

void reallocateMatrix(int* matrix, int rows, int cols)
{
    matrix = realloc(matrix, rows * cols * sizeof(int));
}

_Bool lastRowsAreSame(int* matrix, int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        if (matrix[(rows-1)*cols + i] != matrix[(rows-2)*cols + i])
        {
            return 0;
        }
    }

    return 1;
}

void fillLastVector(int* matrix, int rows, int cols)
{
    int min = INT_MAX;
    int sum = 0;
    for (int i = 0; i < cols-1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j 
                && matrix[i*cols + j] != INT_MAX
                && matrix[(rows-2)*cols + j] != INT_MAX)
            {
                sum = matrix[i*cols + j] + matrix[(rows-2)*cols + j];
                if (sum < min)
                {
                    min = sum;
                }
            }
        }
        matrix[(rows-1)*cols + i] = min;
        min = INT_MAX;
    }
    matrix[(rows-1)*cols + (cols-1)] = 0;
}