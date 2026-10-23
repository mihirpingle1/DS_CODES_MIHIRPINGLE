#include <stdio.h>
#include <string.h>

#define MAX 5

struct PrintJob
{
    int jobID;
    char documentTitle[50];
};

struct PrintJob queue[MAX];

int front = 0;
int rear = 0;

int isFull()
{
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

void enqueue(int jobID, char documentTitle[])
{
    if (isFull())
    {
        printf("Queue Overflow! Print queue is full.\n");
    }
    else
    {
        rear = (rear + 1) % MAX;

        queue[rear].jobID = jobID;
        strcpy(queue[rear].documentTitle, documentTitle);

        printf("Print job added successfully.\n");
    }
}

void dequeue()
{
    struct PrintJob elem;

    if (isEmpty())
    {
        printf("Queue Underflow! No print jobs available.\n");
    }
    else
    {
        front = (front + 1) % MAX;

        elem = queue[front];

        printf("\nProcessing Print Job:\n");
        printf("Job ID: %d\n", elem.jobID);
        printf("Document Title: %s\n", elem.documentTitle);
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("No pending print jobs.\n");
    }
    else
    {
        printf("\nPrint Jobs in Queue:\n");

        i = (front + 1) % MAX;

        while (i != (rear + 1) % MAX)
        {
            printf("Job ID: %d\n", queue[i].jobID);
            printf("Document Title: %s\n", queue[i].documentTitle);
            printf("----------------------\n");

            i = (i + 1) % MAX;
        }
    }
}

int main()
{
    int choice;
    int jobID;
    char documentTitle[50];

    do
    {
        printf("\n----- CIRCULAR PRINT QUEUE -----\n");
        printf("1. Enqueue Print Job\n");
        printf("2. Dequeue Print Job\n");
        printf("3. Display Print Jobs\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &jobID);

                printf("Enter Document Title: ");
                scanf(" %49[^\n]", documentTitle);

                enqueue(jobID, documentTitle);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
