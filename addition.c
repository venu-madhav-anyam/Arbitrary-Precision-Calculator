/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
	Dlist *t1 = *tail1, *t2 = *tail2;
	int result, carry = 0, once = 1;

	while (t1 || t2 || carry)
	{
		result = carry;

		if (t1)
		{
			result += t1->data;
			t1 = t1->prev;
		}

		if (t2)
		{
			result += t2->data;
			t2 = t2->prev;
		}

		carry = result / 10000;

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
		result = 0;
	}
}
