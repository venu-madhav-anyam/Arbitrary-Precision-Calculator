#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#define RESET "\033[0m"
#define RED "\033[1;38;5;202m"
#define GREEN "\033[1;92m"
#define BLUE "\033[1;36m"
#define WHITE "\033[1;37m"

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
} Dlist;

/* Include the prototypes here */
int validate_arguments(int argc, char *argv[]);
int extract_input_data(Dlist **head, Dlist **tail, char str[]);
int operation_valid(char *opt, char *argv[]);
int compare_data(Dlist *head1, Dlist *head2);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);

#endif
