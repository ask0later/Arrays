#include <stdio.h>
#include <assert.h>

struct MATRIX
{
    int* data;
    size_t size_y, size_x;
};

void EnterMatrix(int** ptr, size_t* selectY, size_t* selectX);
void PrintData(size_t size_y, size_t size_x, int* array);
void ResultProduct(MATRIX matrix1, MATRIX matrix2);
//int SelectionProduct(MATRIX matrix1, MATRIX matrix2);


int main()
{
    MATRIX matrix1 = {.data = 0, .size_y = 0, .size_x = 0};
    MATRIX matrix2 = {.data = 0, .size_y = 0, .size_x = 0};
    EnterMatrix(&matrix1.data, &matrix1.size_y, &matrix1.size_x);
    EnterMatrix(&matrix2.data, &matrix2.size_y, &matrix2.size_x);

    PrintData(matrix1.size_y, matrix1.size_x, matrix1.data);
    PrintData(matrix2.size_y, matrix2.size_x, matrix2.data);


    ResultProduct(matrix1, matrix2);

    // const int * [5][5]
}
void PrintData(size_t size_y, size_t size_x, int* array)
{
    for (size_t i = 0; i < size_y; i++)
    {
        printf("\n");
        for (size_t j = 0; j < size_x; j++)
        {
            printf("matrix[%d, %d] = ", i, j);
                                    // size_x
            printf("%4d  ", *(array + size_x * i + j));
        }
    }
    printf("\n");
}


/*
int SelectionProduct(MATRIX matrix1, MATRIX matrix2)
{
    if (matrix1.size_y == matrix2.size_x)
    {
        printf("you may to product matrix2 and matrix1");
        return 2;
    }
    else if (matrix1.size_x == matrix2.size_y)
    {
        printf("you may to product matrix1 and matrix2");
        return 1;
    }
    else
    {
        printf("matrix not may to product");
        return 0;
    }
}
*/
void ResultProduct(MATRIX matrix1, MATRIX matrix2)
{
    MATRIX matrix3 = {.data = 0, .size_y = matrix1.size_y, .size_x = matrix2.size_x};
    int data3[matrix3.size_y][matrix3.size_x] = {0};
    size_t n = matrix1.size_x;

    for (size_t i = 0; i < matrix1.size_y; i++)
    {
        printf("\n");
        for (size_t j = 0; j < matrix2.size_x; j++)
        {
            int val = 0;
            for (size_t k = 0; k < n; k++)
            {
                val = val + ((*(matrix1.data + matrix1.size_x * i + k)) *
                            (*(matrix2.data + k * matrix2.size_x + j)));
            }
            data3[i][j] = val;
        }
    }
    matrix3.data = *data3;
    PrintData(matrix3.size_y, matrix3.size_x, matrix3.data);
}

void EnterMatrix(int** ptr, size_t* selectY, size_t* selectX)
{
    printf("Enter rows and cols of matrix by rotation:\n");
    scanf("%d %d", selectY, selectX);
    printf("enter ech number of matrix:\n");
    *ptr = (int*)calloc((*selectY) * (*selectX), sizeof(int));
    for (size_t i = 0; i < (*selectY) * (*selectX); i++)
    {
        scanf("%d",*ptr + i);
    }
}
