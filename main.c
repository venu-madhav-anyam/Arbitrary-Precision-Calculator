/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include <stdio.h>
#include "apc.h"
#include "ctype.h"

int swap = 0, sign = 0, ok = 0;

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *t = NULL;
	char option, operator, * input;

	// Input validation
	if (validate_arguments(argc, argv) == FAILURE)
		return 1;
	operator= argv[2][0];

	if (extract_input_data(&head1, &tail1, argv[1]) == FAILURE)
		printf(RED "Failed\n");

	if (extract_input_data(&head2, &tail2, argv[3]) == FAILURE)
		printf(RED "Failed\n");

	operation_valid(&operator, argv);

	{
		printf(GREEN "Result is : ");

		switch (operator)
		{
		case '+':
			addition(&head1, &tail1, &head2, &tail2, &headR);

			if (compare_data(head1, head2) == FAILURE && (argv[1][0] == '-' && argv[3][0] == '-') && ok)
				;
			else if (sign)
				printf(WHITE "-");

			t = headR;
			int first = 1;
			while (t)
			{
				if (first)
				{
					printf(WHITE "%d", t->data);
					first = 0;
				}
				else
					printf(WHITE "%04d", t->data);
				t = t->next;
			}

			break;
		case '-':
			subtraction(&head1, &tail1, &head2, &tail2, &headR);

			if (compare_data(head1, head2) == FAILURE && (argv[1][0] == '-' && argv[3][0] == '-'))
				;
			else if (swap == 1 && headR->data)
				printf(WHITE "-");

			else if (sign && argv[2][0] == '+' && swap != 1 && headR->data)
			{
				printf(WHITE "-");
			}

			else if (sign && (argv[1][0] == '-' && argv[3][0] == '-') && headR->data)
				printf(WHITE "-");

			t = headR;
			int s = 1;
			while (t)
			{
				if (s)
				{
					printf(WHITE "%d", t->data);
					s = 0;
				}
				else
					printf(WHITE "%04d", t->data);
				t = t->next;
			}

			break;
		case 'x':
		case 'X':
			multiplication(&head1, &tail1, &head2, &tail2, &headR);

			if (sign)
				printf(WHITE "-");

			t = headR;
			int f = 1;
			while (t)
			{
				if (f)
				{
					printf(WHITE "%d", t->data);
					f = 0;
				}
				else
					printf(WHITE "%04d", t->data);
				t = t->next;
			}

			break;
		case '/':
			division(&head1, &tail1, &head2, &tail2, &headR);
			break;
		default:
			printf(RED "Invalid Input :-( Try again...\n");
		}
	}

	printf("\n");

	return 0;
}
