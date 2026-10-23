#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} pnode;

pnode *new_poly()
{
    pnode *head = (pnode *)malloc(sizeof(pnode));

    if (head != NULL)
    {
        head->coef = 0;
        head->exp = -1;
        head->next = head;
    }

    return head;
}

void insert_term(pnode *head, int coef, int exp)
{
    if (head == NULL || coef == 0)
        return;

    pnode *prev = head;
    pnode *curr = head->next;

    while (curr != head && curr->exp > exp)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr != head && curr->exp == exp)
    {
        curr->coef += coef;

        if (curr->coef == 0)
        {
            prev->next = curr->next;
            free(curr);
        }
    }
    else
    {
        pnode *newNode = (pnode *)malloc(sizeof(pnode));

        if (newNode != NULL)
        {
            newNode->coef = coef;
            newNode->exp = exp;
            newNode->next = curr;
            prev->next = newNode;
        }
    }
}

pnode *read_poly()
{
    pnode *head = new_poly();
    int ch, c, e;

    if (head == NULL)
        return NULL;

    while (1)
    {
        printf("Do you want to enter a term? (1 = yes, 0 = no): ");

        if (scanf("%d", &ch) != 1 || ch != 1)
            break;

        printf("Enter coefficient and exponent: ");

        if (scanf("%d %d", &c, &e) != 2)
            break;

        insert_term(head, c, e);
    }

    return head;
}

pnode *poly_add(pnode *h1, pnode *h2)
{
    pnode *sum = new_poly();

    if (sum == NULL)
        return NULL;

    if (h1 != NULL)
    {
        pnode *p1 = h1->next;

        while (p1 != h1)
        {
            insert_term(sum, p1->coef, p1->exp);
            p1 = p1->next;
        }
    }

    if (h2 != NULL)
    {
        pnode *p2 = h2->next;

        while (p2 != h2)
        {
            insert_term(sum, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }

    return sum;
}

void print_poly(pnode *head)
{
    if (head == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    pnode *p = head->next;

    if (p == head)
    {
        printf("0\n");
        return;
    }

    while (p != head)
    {
        printf("%+dx^%d", p->coef, p->exp);
        p = p->next;

        if (p != head)
            printf(" ");
    }

    printf("\n");
}

void free_poly(pnode *head)
{
    if (head == NULL)
        return;

    pnode *curr = head->next;

    while (curr != head)
    {
        pnode *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(head);
}

int main()
{
    pnode *p1, *p2, *sum;

    printf("Enter the first polynomial:\n");
    p1 = read_poly();

    if (p1 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nEnter the second polynomial:\n");
    p2 = read_poly();

    if (p2 == NULL)
    {
        printf("Memory allocation failed.\n");
        free_poly(p1);
        return 1;
    }

    sum = poly_add(p1, p2);

    if (sum == NULL)
    {
        printf("Memory allocation failed.\n");
        free_poly(p1);
        free_poly(p2);
        return 1;
    }

    printf("\nP1 = ");
    print_poly(p1);

    printf("P2 = ");
    print_poly(p2);

    printf("SUM = ");
    print_poly(sum);

    free_poly(p1);
    free_poly(p2);
    free_poly(sum);

    return 0;
}
