#include <stdio.h>
#include "apc.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

extern int sign;

int validate_arguments(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf(RED "Error : Insufficient Arguments.\n");
        printf(RED "Usage : ./a.out   <Operand1> <operator> <operand2>\n");
        printf(RED "For Addition '+'.\nFor Subtraction '-'\nFor Multiplication 'x'\nFor Division '/'\n");
        return FAILURE;
    }

    for (int i = 0; i < argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]) && (argv[1][i] != '-' && argv[1][i] != '-'))
        {
            printf(RED "Error : Invalid Input (operand 1).\n");
            return FAILURE;
        }
    }

    if (!((argv[2][0] == '+') || (argv[2][0] == '-') || (argv[2][0] == '/') || (argv[2][0] == 'x') || (argv[2][0] == 'X')))
    {
        printf(RED "Error : Invalid operator.\n");
        return FAILURE;
    }

    for (int i = 0; i < argv[3][i] != '\0'; i++)
    {
        if (!isdigit(argv[3][i]) && (argv[3][i] != '-' && argv[3][i] != '-'))
        {
            printf(RED "Error : Invalid Input (operand 2).\n");
            return FAILURE;
        }
    }
}

int extract_input_data(Dlist **head, Dlist **tail, char str[])
{
    char data[30];

    strcpy(data, str);
    int l = strlen(data);

    while (l)
    {
        Dlist *node = malloc(sizeof(Dlist));

        if (!node)
            return FAILURE;

        node->prev = NULL;
        node->next = NULL;
        data[l] = '\0';
        if (l < 5)
        {
            node->data = abs(atoi(data));
            l = 0;
        }
        else
        {
            node->data = abs(atoi(data + (l - 4)));
            l -= 4;
        }

        if (!*head)
        {
            node->next = NULL;
            *head = *tail = node;
        }
        else
        {
            node->next = *head;
            (*head)->prev = node;
            *head = node;
        }
    }

    // Dlist *temp = *head;
    // while (temp)
    // {
    //     printf("%d", temp->data);
    //     temp = temp->next;
    // }
    // printf("\n");
}

int operation_valid(char *opt, char *argv[])
{
    if (*opt == '+')
    {

        if (argv[1][0] == '-' || argv[3][0] == '-')
        {
            *opt = '-';

            if (argv[1][0] == '-')
                sign = 1;
        }

        if (argv[1][0] == '-' && argv[3][0] == '-')
            *opt = '+';

        return SUCCESS;
    }

    if (*opt == '-')
    {
        if (argv[1][0] == '-' && argv[3][0] == '-')
            sign = 1;
        else if (argv[1][0] == '-' || argv[3][0] == '-')
        {
            *opt = '+';

            if (argv[1][0] == '-')
                sign = 1;
        }

        return SUCCESS;
    }

    if (*opt == 'x' || *opt == 'X')
    {
        if (argv[1][0] == '-' && argv[3][0] == '-')
            sign = 0;
        else if (argv[1][0] == '-' || argv[3][0] == '-')
            sign = 1;

        return SUCCESS;
    }

    if (*opt == '/')
    {
        if (argv[1][0] == '-' && argv[3][0] == '-')
            sign = 0;
        else if (argv[1][0] == '-' || argv[3][0] == '-')
            sign = 1;

        return SUCCESS;
    }
}

int compare_data(Dlist *head1, Dlist *head2)
{
    Dlist *t1 = head1, *t2 = head2;
    int op1 = 0, op2 = 0;

    while (t1 || t2)
    {
        if (t1)
        {
            t1 = t1->next;
            op1++;
        }

        if (t2)
        {
            t2 = t2->next;
            op2++;
        }
    }

    if (op1 > op2)
    {
        return SUCCESS;
    }
    else if (op2 > op1)
    {
        return FAILURE;
    }
    else if (op1 == op2)
    {
        t1 = head1, t2 = head2;
        while (t1 && t2)
        {
            if (t1->data > t2->data)
            {
                return FAILURE;
            }
            else if (t1->data < t2->data)
            {
                return SUCCESS;
            }

            t1 = t1->next;
            t2 = t2->next;
        }
    }
}
