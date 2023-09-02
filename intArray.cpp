#include <stdio.h>
#include <assert.h>

struct MATRIX
{
    int* data;
    const size_t size_y, size_x;
};


void PrintData1(MATRIX matrix1);
void PrintData2(MATRIX matrix2);
void ResultProduct(MATRIX matrix1, MATRIX matrix2);
int SelectionProduct(MATRIX matrix1, MATRIX matrix2);


int main()
{
    MATRIX matrix1 = {.data = 0, .size_y = 3, .size_x = 2};
    MATRIX matrix2 = {.data = 0, .size_y = 2, .size_x = 3};

    /*const matrix1.size_y = 3;
    const matrix1.size_x = 2;

    const matrix2.size_y = 2;
    const matrix2.size_x = 3;*/

    int data1[matrix1.size_y][matrix1.size_x] = {{2,  3},
                                                 {3, -1},
                                                 {-3, 2}};

    int data2[matrix2.size_y][matrix2.size_x] = {{2, -3, -1},
                                                 {3,  1,  1}};

    matrix1.data = *data1;
    matrix2.data = *data2;

    PrintData1(matrix1);
    PrintData2(matrix2);
    printf("\n");

    ResultProduct(matrix1, matrix2);
    // const int * [5][5]
}
void PrintData1(MATRIX matrix1)
{
    for (size_t i = 0; i < matrix1.size_y; i++)
    {
        printf("\n");
        for (size_t j = 0; j < matrix1.size_x; j++)
        {
            printf("a[%d, %d] = ", i, j);
                                    // size_x
            printf("%2d  ", *(matrix1.data + matrix1.size_x * i + j));
        }
    }
    printf("\n");
}

void PrintData2(MATRIX matrix2)
{
    for (size_t i = 0; i < matrix2.size_y; i++)
    {
        printf("\n");
        for (size_t j = 0; j < matrix2.size_x; j++)
        {
            printf("b[%d, %d] = ", i, j);
                                    // size_x
            printf("%2d  ", *(matrix2.data + matrix2.size_x * i + j));
        }
    }

    printf("\n");
}

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
                //data1[i][k] * data2[k][j];
            }

            data3[i][j] = val;

            printf("c[%d,%d] = %3d ", i, j, data3[i][j]);
        }
    }
    matrix3.data = *data3;
}
