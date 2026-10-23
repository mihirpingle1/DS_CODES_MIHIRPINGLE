#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int regNo;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

void addStudent()
{
    struct Student *newNode, *temp;

    newNode = (struct Student *)malloc(sizeof(struct Student));

    if(newNode == NULL)
    {
        printf("\nMemory allocation failed.\n");
        return;
    }

    printf("\nEnter Registration Number: ");
    scanf("%d", &newNode->regNo);
    getchar();

    printf("Enter Student Name: ");
    fgets(newNode->name, sizeof(newNode->name), stdin);
    newNode->name[strcspn(newNode->name, "\n")] = '\0';

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nStudent added successfully.\n");
}

void removeStudent()
{
    struct Student *temp, *prev;
    int regNo;

    if(head == NULL)
    {
        printf("\nNo students registered.\n");
        return;
    }

    printf("\nEnter Registration Number to remove: ");
    scanf("%d", &regNo);

    temp = head;
    prev = NULL;

    while(temp != NULL && temp->regNo != regNo)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nStudent not found.\n");
        return;
    }

    if(prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("\nStudent record deleted successfully.\n");
}

void displayList()
{
    struct Student *temp;

    if(head == NULL)
    {
        printf("\nNo students registered.\n");
        return;
    }

    temp = head;

    printf("\n----------------------------------------\n");
    printf("Registration No.\tStudent Name\n");
    printf("----------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d\t\t\t%s\n", temp->regNo, temp->name);
        temp = temp->next;
    }

    printf("----------------------------------------\n");
}

void countStudents()
{
    struct Student *temp;
    int count = 0;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\nTotal registered students: %d\n", count);
}

void sortList()
{
    struct Student *i, *j;
    int tempReg;
    char tempName[50];

    if(head == NULL)
    {
        printf("\nNo students registered.\n");
        return;
    }

    for(i = head; i->next != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->regNo > j->regNo)
            {
                tempReg = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempReg;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("\nStudents sorted by Registration Number.\n");
    displayList();
}

void reverseList()
{
    struct Student *prev = NULL;
    struct Student *current = head;
    struct Student *nextNode;

    if(head == NULL)
    {
        printf("\nNo students registered.\n");
        return;
    }

    while(current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;

    printf("\nList reversed successfully.\n");
    displayList();
}

void freeList()
{
    struct Student *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== WORKSHOP ENROLLMENT SYSTEM =====\n");
        printf("1. Add a Student\n");
        printf("2. Remove a Student\n");
        printf("3. Display the List\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort the List\n");
        printf("6. Reverse the List\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                displayList();
                break;

            case 4:
                countStudents();
                break;

            case 5:
                sortList();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                freeList();
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 7);

    return 0;
}
