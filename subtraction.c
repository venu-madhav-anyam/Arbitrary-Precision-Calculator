/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

extern int swap, sign;

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	while (*head1 && (*head1)->data == 0 && (*head1)->next)
	{
		Dlist *t = *head1;
		*head1 = (*head1)->next;
		free(t);
		(*head1)->prev=NULL;
	}

	while (*head2 && (*head2)->data == 0 && (*head2)->next)
	{
		Dlist *t = *head2;
		*head2 = (*head2)->next;
		free(t);
		(*head2)->prev=NULL;
	}

	Dlist *t1 = *head1, *t2 = *head2, *t;
	int result, borrow = 0, op1 = 0, op2 = 0, once = 1;

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
		t1 = *tail1;
		t2 = *tail2;
		swap = -1;
		//sign = 1;
	}
	else if (op2 > op1)
	{
		t1 = *tail2;
		t2 = *tail1;
		swap = 1;
	}
	else if (op1 == op2)
	{
		t1 = *head1, t2 = *head2;
		while (t1 && t2)
		{
			if (t1->data > t2->data)
			{
				t1 = *tail1;
				t2 = *tail2;
				swap = -1;
				sign = 1;
				break;
			}
			else if (t1->data < t2->data)
			{
				t1 = *tail2;
				t2 = *tail1;
				swap = 1;
				break;
			}

			t1 = t1->next;
			t2 = t2->next;
		}

		if (!swap)
		{
			Dlist *new = malloc(sizeof(Dlist));
			new->data = 0;
			new->next = new->prev = NULL;
			*headR = new;
			return SUCCESS;
		}
	}

	while (t1 || t2)
	{
		if (t1)
		{
			result = t1->data - borrow;
			if (result < 0)
			{
				result += 10000;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}

			t1 = t1->prev;
		}

		if (t2)
		{
			result -= t2->data;
			if (result < 0)
			{
				result += 10000;
				borrow = 1;
			}
			t2 = t2->prev;
		}

		if (t1 || t2 || result)
		{
			if (once)
			{
				*headR = NULL;
				once = 0;
			}

			Dlist *new = malloc(sizeof(Dlist));

			if (!new)
				return FAILURE;

			new->data = result % 10000;
			new->prev = NULL;

			if (!*headR)
			{
				*headR = new;
				new->next = NULL;
			}
			else
			{
				new->next = *headR;
				(*headR)->prev = new;
				*headR = new;
			}

			
		}
		result = 0;
	}

	while ((*headR)->data == 0)
	{
		t = *headR;
		*headR = (*headR)->next;
		free(t);
	}

	return SUCCESS;
}
