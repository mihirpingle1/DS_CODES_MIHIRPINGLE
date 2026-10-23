#include <stdio.h>

#define MAX 100

void display(int a[MAX][3], int n)
{
    int i;

    printf("\nRow\tColumn\tValue\n");

    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
    }
}

void createSparse(int a[MAX][3])
{
    int r, c, i, j, value;
    int k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &value);

            if (value != 0)
            {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = value;
                k++;
            }
        }
    }

    a[0][0] = r;
    a[0][1] = c;
    a[0][2] = k - 1;
}

void simpleTranspose(int a[MAX][3], int b[MAX][3])
{
    int i, j, k = 1;
    int rows = a[0][0];
    int cols = a[0][1];
    int terms = a[0][2];

    b[0][0] = cols;
    b[0][1] = rows;
    b[0][2] = terms;

    for (i = 0; i < cols; i++)
    {
        for (j = 1; j <= terms; j++)
        {
            if (a[j][1] == i)
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

void fastTranspose(int a[MAX][3], int b[MAX][3])
{
    int total[MAX] = {0};
    int index[MAX] = {0};
    int i, col, terms;

    terms = a[0][2];

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = terms;

    if (terms == 0)
        return;

    for (i = 1; i <= terms; i++)
    {
        total[a[i][1]]++;
    }

    index[0] = 1;

    for (i = 1; i < a[0][1]; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    for (i = 1; i <= terms; i++)
    {
        col = a[i][1];

        b[index[col]][0] = a[i][1];
        b[index[col]][1] = a[i][0];
        b[index[col]][2] = a[i][2];

        index[col]++;
    }
}

int main()
{
    int a[MAX][3];
    int b[MAX][3];
    int c[MAX][3];

    createSparse(a);

    printf("\nOriginal Sparse Matrix in Triplet Form:");
    display(a, a[0][2]);

    simpleTranspose(a, b);

    printf("\nSimple Transpose:");
    display(b, b[0][2]);

    fastTranspose(a, c);

    printf("\nFast Transpose:");
    display(c, c[0][2]);

    return 0;
}
