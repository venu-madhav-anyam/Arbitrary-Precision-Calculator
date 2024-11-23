/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

void create_node(Dlist **head, int data)
{
	Dlist *new;

	new = malloc(sizeof(Dlist));
	if (!new)
		return;

	new->data = data % 10000;
	new->next = new->prev = NULL;

	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
	}

	*head = new;
}

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	Dlist *t1 = *tail1, *t2 = *tail2;
	Dlist *res1 = NULL, *res2 = NULL;
	int carry = 0, pdt = 0, count = 1;

	while (t2)
	{
		carry = 0;
		t1 = *tail1;

		while (t1)
		{
			pdt = t1->data * t2->data + carry;

			create_node(&res2, pdt % 10000);

			carry = pdt / 10000;
			t1 = t1->prev;
		}

		if (carry)
		{
			create_node(&res2, carry);
		}

		Dlist *r1 = res1, *r2 = res2;
		while (r2 && r2->next)
		{
			r2 = r2->next;
		}

		while (r1 && r1->next)
		{
			r1 = r1->next;
		}

		addition(&res1, &r1, &res2, &r2, &res1);

		t2 = t2->prev;

		res2 = NULL;
		for (int i = 0; i < count; i++)
		{
			create_node(&res2, 0);
		}
		count++;
	}

	while (res1 && res1->data == 0)
	{
		Dlist *t = res1;
		res1 = res1->next;
		free(t);
	}

	if (!res1)
	{
		create_node(&res1, 0);
	}

	*headR = res1;
}
