#include <stdio.h>

#define MAX 20

void displayMatrix(int mat[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int Mat1[MAX][MAX], int Mat2[MAX][MAX],
               int R1, int R2, int C1, int C2)
{
    int s[MAX][MAX];
    int i, j;

    if (R1 == R2 && C1 == C2)
    {
        printf("\nAddition:\n");

        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C1; j++)
            {
                s[i][j] = Mat1[i][j] + Mat2[i][j];
            }
        }

        displayMatrix(s, R1, C1);
    }
    else
    {
        printf("\nMatrices cannot be added.\n");
    }
}

void subMatrix(int Mat1[MAX][MAX], int Mat2[MAX][MAX],
               int R1, int R2, int C1, int C2)
{
    int m[MAX][MAX];
    int i, j;

    if (R1 == R2 && C1 == C2)
    {
        printf("\nSubtraction:\n");

        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C1; j++)
            {
                m[i][j] = Mat1[i][j] - Mat2[i][j];
            }
        }

        displayMatrix(m, R1, C1);
    }
    else
    {
        printf("\nMatrices cannot be subtracted.\n");
    }
}

void transpose(int mat[MAX][MAX], int r, int c)
{
    int i, j;
    int t[MAX][MAX];

    printf("\nTranspose:\n");

    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            t[i][j] = mat[j][i];
        }
    }

    displayMatrix(t, c, r);
}

void multiMatrix(int Mat1[MAX][MAX], int Mat2[MAX][MAX],
                 int R1, int R2, int C1, int C2)
{
    int mul[MAX][MAX];
    int i, j, k, sum;

    if (C1 == R2)
    {
        printf("\nMultiplication:\n");

        for (i = 0; i < R1; i++)
        {
            for (j = 0; j < C2; j++)
            {
                sum = 0;

                for (k = 0; k < C1; k++)
                {
                    sum = sum + Mat1[i][k] * Mat2[k][j];
                }

                mul[i][j] = sum;
            }
        }

        displayMatrix(mul, R1, C2);
    }
    else
    {
        printf("\nMatrices cannot be multiplied.\n");
    }
}

int main()
{
    int Mat1[MAX][MAX], Mat2[MAX][MAX];
    int R1, R2, C1, C2;
    int i, j;

    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &R1, &C1);

    if (R1 < 1 || R1 > MAX || C1 < 1 || C1 > MAX)
    {
        printf("Invalid dimensions for the first matrix.\n");
        return 1;
    }

    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &R2, &C2);

    if (R2 < 1 || R2 > MAX || C2 < 1 || C2 > MAX)
    {
        printf("Invalid dimensions for the second matrix.\n");
        return 1;
    }

    printf("\nEnter elements of the first matrix:\n");

    for (i = 0; i < R1; i++)
    {
        for (j = 0; j < C1; j++)
        {
            scanf("%d", &Mat1[i][j]);
        }
    }

    printf("\nEnter elements of the second matrix:\n");

    for (i = 0; i < R2; i++)
    {
        for (j = 0; j < C2; j++)
        {
            scanf("%d", &Mat2[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    displayMatrix(Mat1, R1, C1);

    printf("\nSecond Matrix:\n");
    displayMatrix(Mat2, R2, C2);

    addMatrix(Mat1, Mat2, R1, R2, C1, C2);
    subMatrix(Mat1, Mat2, R1, R2, C1, C2);
    multiMatrix(Mat1, Mat2, R1, R2, C1, C2);
    transpose(Mat1, R1, C1);

    return 0;
}
