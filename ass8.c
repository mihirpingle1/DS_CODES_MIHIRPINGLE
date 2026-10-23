#include <stdio.h>
#include <string.h>

#define MAX 5

struct PrintJob
{
    int jobID;
    char documentTitle[50];
};

struct PrintJob queue[MAX];

int front = -1;
int rear = -1;

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)
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
        if (front == -1)
            front = 0;

        rear++;

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
        elem = queue[front];

        printf("\nProcessing Print Job:\n");
        printf("Job ID: %d\n", elem.jobID);
        printf("Document Title: %s\n", elem.documentTitle);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("No Pending Print Jobs.\n");
    }
    else
    {
        printf("\nPrint Jobs in Queue:\n");

        for (i = front; i <= rear; i++)
        {
            printf("Job ID: %d\n", queue[i].jobID);
            printf("Document Title: %s\n", queue[i].documentTitle);
            printf("----------------------\n");
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
        printf("\n----- PRINT QUEUE -----\n");
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
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
