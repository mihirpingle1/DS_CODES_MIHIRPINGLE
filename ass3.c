#include <stdio.h>
#include <string.h>

struct MovieCD
{
    int cd_id;
    char title[20];
    float price;
};

void accept(struct MovieCD c[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Movie CD %d\n", i + 1);

        printf("Enter CD ID: ");
        scanf("%d", &c[i].cd_id);

        printf("Enter Title: ");
        scanf("%19s", c[i].title);

        printf("Enter Price: ");
        scanf("%f", &c[i].price);
    }
}

void display(struct MovieCD c[], int n)
{
    int i;

    printf("\n------------------------------------------\n");
    printf("CD ID\tTitle\t\tPrice\n");
    printf("------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%-15s\t%.2f\n",
               c[i].cd_id, c[i].title, c[i].price);
    }

    printf("------------------------------------------\n");
}

void bubblesort(struct MovieCD c[], int n)
{
    int i, j;
    struct MovieCD temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(c[j].cd_id > c[j + 1].cd_id)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

void selectionsort(struct MovieCD c[], int n)
{
    int i, j, min;
    struct MovieCD temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(c[j].cd_id < c[min].cd_id)
                min = j;
        }

        if(min != i)
        {
            temp = c[i];
            c[i] = c[min];
            c[min] = temp;
        }
    }
}

void insertionsort(struct MovieCD c[], int n)
{
    int i, j;
    struct MovieCD temp;

    for(i = 1; i < n; i++)
    {
        temp = c[i];
        j = i - 1;

        while(j >= 0 && c[j].cd_id > temp.cd_id)
        {
            c[j + 1] = c[j];
            j--;
        }

        c[j + 1] = temp;
    }
}

void shellsort(struct MovieCD c[], int n)
{
    int gap, i, j;
    struct MovieCD temp;

    for(gap = n / 2; gap > 0; gap /= 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = c[i];
            j = i;

            while(j >= gap && c[j - gap].cd_id > temp.cd_id)
            {
                c[j] = c[j - gap];
                j -= gap;
            }

            c[j] = temp;
        }
    }
}

void merge(struct MovieCD c[], int low, int mid, int high)
{
    struct MovieCD temp[20];
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(c[i].cd_id <= c[j].cd_id)
            temp[k++] = c[i++];
        else
            temp[k++] = c[j++];
    }

    while(i <= mid)
        temp[k++] = c[i++];

    while(j <= high)
        temp[k++] = c[j++];

    for(i = low; i <= high; i++)
        c[i] = temp[i];
}

void mergesort(struct MovieCD c[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(c, low, mid);
        mergesort(c, mid + 1, high);
        merge(c, low, mid, high);
    }
}

int linearsearch(struct MovieCD c[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(c[i].cd_id == key)
            return i;
    }

    return -1;
}

int stringsearch(struct MovieCD c[], int n, char key[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(strcmp(c[i].title, key) == 0)
            return i;
    }

    return -1;
}

int binarysearch(struct MovieCD c[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = low + (high - low) / 2;

        if(c[mid].cd_id == key)
            return mid;
        else if(key < c[mid].cd_id)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    struct MovieCD c[20];
    int n, choice, key, pos;
    char title[20];

    printf("Enter number of Movie CDs (1-20): ");
    scanf("%d", &n);

    if(n < 1 || n > 20)
    {
        printf("Invalid number of Movie CDs!\n");
        return 0;
    }

    accept(c, n);

    do
    {
        printf("\n\n----- MOVIE CD DATABASE -----\n");
        printf("1. Display Movie CDs\n");
        printf("2. Bubble Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Shell Sort\n");
        printf("6. Merge Sort\n");
        printf("7. Linear Search by CD ID\n");
        printf("8. Linear Search by Title\n");
        printf("9. Binary Search by CD ID\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(c, n);
                break;

            case 2:
                bubblesort(c, n);
                printf("\nAfter Bubble Sort:\n");
                display(c, n);
                break;

            case 3:
                selectionsort(c, n);
                printf("\nAfter Selection Sort:\n");
                display(c, n);
                break;

            case 4:
                insertionsort(c, n);
                printf("\nAfter Insertion Sort:\n");
                display(c, n);
                break;

            case 5:
                shellsort(c, n);
                printf("\nAfter Shell Sort:\n");
                display(c, n);
                break;

            case 6:
                mergesort(c, 0, n - 1);
                printf("\nAfter Merge Sort:\n");
                display(c, n);
                break;

            case 7:
                printf("Enter CD ID to search: ");
                scanf("%d", &key);

                pos = linearsearch(c, n, key);

                if(pos == -1)
                    printf("\nMovie CD Not Found!\n");
                else
                {
                    printf("\nMovie CD Found!\n");
                    printf("CD ID\tTitle\t\tPrice\n");
                    printf("%d\t%-15s\t%.2f\n",
                           c[pos].cd_id,
                           c[pos].title,
                           c[pos].price);
                }
                break;

            case 8:
                printf("Enter title to search: ");
                scanf("%19s", title);

                pos = stringsearch(c, n, title);

                if(pos == -1)
                    printf("\nMovie CD Not Found!\n");
                else
                {
                    printf("\nMovie CD Found!\n");
                    printf("CD ID\tTitle\t\tPrice\n");
                    printf("%d\t%-15s\t%.2f\n",
                           c[pos].cd_id,
                           c[pos].title,
                           c[pos].price);
                }
                break;

            case 9:
                bubblesort(c, n);

                printf("\nCDs sorted by ID for Binary Search:\n");
                display(c, n);

                printf("Enter CD ID to search: ");
                scanf("%d", &key);

                pos = binarysearch(c, n, key);

                if(pos == -1)
                    printf("\nMovie CD Not Found!\n");
                else
                {
                    printf("\nMovie CD Found!\n");
                    printf("CD ID\tTitle\t\tPrice\n");
                    printf("%d\t%-15s\t%.2f\n",
                           c[pos].cd_id,
                           c[pos].title,
                           c[pos].price);
                }
                break;

            case 10:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 10);

    return 0;
}
