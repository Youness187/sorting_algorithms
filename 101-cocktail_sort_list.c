#include "sort.h"

void swap_node(listint_t *p, listint_t *n, listint_t **l);
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *head;

	head = *list;
	while (swapped == 0)
	{
		swapped = 1;
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				swap_node(head, head->next, list);
				print_list(*list);
				swapped = 0;
			}
			else
				head = head->next;
		}
		if (swapped == 1)
			break;
		swapped = 1;
		while (head->prev != NULL)
		{
			if (head->n < head->prev->n)
			{
				swap_node(head->prev, head, list);
				print_list((const listint_t *)*list);
				swapped = 0;
			}
			else
				head = head->prev;
		}
	}
}
/**
 * swap_node - swaping node
 * @p: the prev node
 * @n: the next node
 * @l: the list
 */

void swap_node(listint_t *p, listint_t *n, listint_t **l)
{
	p->next = n->next;
	if (n->next != NULL)
		n->next->prev = p;
	n->prev = p->prev;
	n->next = p;
	if (p->prev != NULL)
		p->prev->next = n;
	else
		*l = n;
	p->prev = n;
}

