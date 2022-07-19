#include "deck.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if equal
 */
int _strcmp(char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 == '\0')
			return (*s1);
		if (*s2 > *s1)
			return (*s1 - *s2);
		if (*s1 > *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (*s2);
	return (0);
}
/**
 * node_swap - Swaps two nodes of doubly linked list
 * @node: node to swap
 * @deck: double link list head
 * Return: void
 */
void node_swap(deck_node_t **node, deck_node_t **deck)
{
	deck_node_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*deck = (*node)->next;
	tmp = tmp3 = *node;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;
	if (tmp2->prev)
		tmp2->prev->next = tmp2;
	if (tmp->next)
		tmp->next->prev = tmp;
	*node = tmp2;
}

/**
 * card_value - Obtains poker card value from node
 * @cardNode: node of poker card
 * Return: Value between 1 and 52
 */
int card_value(deck_node_t *cardNode)
{
	char *cardnum[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			     "Jack", "Queen", "King"};
	int value, i;
	const char *cnum;

	cnum = cardNode->card->value;
	for (i = 0; i < 13;  i++)
	{
		if (!_strcmp(cardnum[i], cnum))
		{
			i++;
			break;
		}
	}
	value = i + (cardNode->card->kind) * 13;
	return (value);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: doubly linked list
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *head, *tback, *aux;

	if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
		return;
	head = *deck;
	while (head && head->next)
	{
		if (card_value(head) > card_value(head->next))
		{
			aux = head;
			node_swap(&aux, deck);
			head = aux;
			tback = aux;
			while (tback && tback->prev)
			{
				if (card_value(tback) < card_value(tback->prev))
				{
					aux = tback->prev;
					node_swap(&(aux), deck);
					tback = aux->next;
				}
				tback = tback->prev;
			}
		}
		head = head->next;
	}
}
