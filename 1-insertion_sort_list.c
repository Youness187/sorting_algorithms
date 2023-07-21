#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *list_p, *list_n;
	int bool;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	bool = 0;
	list_n = *list;
	list_p = list_n->prev;

	while (bool == 0)
	{
		while (list_p != NULL && list_p->n > list_n->n)
		{
			list_p->next = list_n->next;
			if (list_n->next != NULL)
				list_n->next->prev = list_p;
			else
				bool = 1;
			list_n->prev = list_p->prev;
			list_n->next = list_p;
			if (list_p->prev != NULL)
				list_p->prev->next = list_n;
			else
				*list = list_n;
			list_p->prev = list_n;
			list_p = list_n->prev;
			print_list((const listint_t *)*list);
		}
		list_n = list_n->next;

		if (list_n == NULL)
			break;
		list_p = list_n->prev;
	}
}

