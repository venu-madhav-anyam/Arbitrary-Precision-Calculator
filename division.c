/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

extern int sign;
long count = 0;

int compare(Dlist *head1, Dlist **head2)
{
	Dlist *t1 = head1, *t2 = *head2, *t;
	int op1 = 0, op2 = 0;

	if (!t1 || !t2 || t1->data == 0 || t2->data == 0)
		return FAILURE;

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

	if (op1 < op2)
		return FAILURE;
	else if (op1 == op2)
	{
		t1 = head1, t2 = *head2;
		while (t1 && t2)
		{
			if (t1->data > t2->data)
				return SUCCESS;

			if (t1->data <= t2->data)
			{
				if (t1->data == 0)
					return SUCCESS;
				else if (t1->data == t2->data)
					count++;

				return FAILURE;
			}

			t1 = t1->next;
			t2 = t2->next;
		}
	}
	else
		return SUCCESS;
}

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{

	while (*head1 && (*head1)->data == 0 && (*head1)->next)
	{
		Dlist *t = *head1;
		*head1 = (*head1)->next;
		free(t);
		(*head1)->prev = NULL;
	}

	while (*head2 && (*head2)->data == 0 && (*head2)->next)
	{
		Dlist *t = *head2;
		*head2 = (*head2)->next;
		free(t);
		(*head2)->prev = NULL;
	}

	if ((*head2)->data == 0)
	{
		printf(WHITE "Cannot divide by zero.");
		return SUCCESS;
	}
	else if ((*head1)->data == 0)
	{
		printf(WHITE "0");
		return SUCCESS;
	}

	Dlist *t1 = *head1, *t2 = *head2, *result, *t;

	result = *head1;
	t2 = *tail1;

	while (compare(result, head2) != FAILURE)
	{
		subtraction(&result, &t2, head2, tail2, &result);

		t1 = result;

		while (t1)
		{
			t2 = t1;
			t1 = t1->next;
		}

		// t = result;
		// while (t)
		// {
		// 	printf("%04d", t->data);
		// 	t = t->next;
		// }

		count++;

		// printf("\ncount : %ld\n",count);
	}

	if (sign)
		printf(WHITE "-");

	printf(WHITE "%ld", count);
}