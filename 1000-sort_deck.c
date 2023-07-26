#include "deck.h"
void insertion_sort_kind(deck_node_t **list);
void insertion_sort_value(deck_node_t **list);
int get_val(const char *card);
/**
 * sort_deck - function that sorts a deck of cards
 * @deck: deck list
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_kind(deck);
	insertion_sort_value(deck);
}

/**
 * insertion_sort_kind - Sort a deck of cards from spades to diamonds
 * @list: list
 */
void insertion_sort_kind(deck_node_t **list)
{
	deck_node_t *list_p, *list_n;
	int bool;

	bool = 0;
	list_n = *list;
	list_p = list_n->prev;

	while (bool == 0)
	{
		while (list_p != NULL && list_p->card->kind > list_n->card->kind)
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
		}
		list_n = list_n->next;

		if (list_n == NULL)
			break;
		list_p = list_n->prev;
	}
}
/**
 * insertion_sort_value - Sort a deck of cards sorted from ace to king
 * @list: list
 */
void insertion_sort_value(deck_node_t **list)
{
	deck_node_t *list_p, *list_n;
	int bool;

	bool = 0;
	list_n = *list;
	list_p = list_n->prev;

	while (bool == 0)
	{
		while (list_p != NULL && list_p->card->kind == list_n->card->kind
				&& get_val(list_p->card->value) > get_val(list_n->card->value))
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
		}
		list_n = list_n->next;

		if (list_n == NULL)
			break;
		list_p = list_n->prev;
	}
}
/**
 * get_val - Get the number of a card
 * @card: card string
 * Return: The numerical value of the card
 */
int get_val(const char *card)
{
	if (strcmp(card, "Ace") == 0)
		return (0);
	if (strcmp(card, "1") == 0)
		return (1);
	if (strcmp(card, "2") == 0)
		return (2);
	if (strcmp(card, "3") == 0)
		return (3);
	if (strcmp(card, "4") == 0)
		return (4);
	if (strcmp(card, "5") == 0)
		return (5);
	if (strcmp(card, "6") == 0)
		return (6);
	if (strcmp(card, "7") == 0)
		return (7);
	if (strcmp(card, "8") == 0)
		return (8);
	if (strcmp(card, "9") == 0)
		return (9);
	if (strcmp(card, "10") == 0)
		return (10);
	if (strcmp(card, "Jack") == 0)
		return (11);
	if (strcmp(card, "Queen") == 0)
		return (12);
	return (13);
}

