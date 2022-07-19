#include "sort.h"

/**
 * node_swap - Swaps two nodes of doubly linked list
 * @node: node to swap
 * @list: double link list head
 * Return: void
 */
void node_swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*list = (*node)->next;
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
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: head of list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tmp;
	int c = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && c != m)
		{
			if (head->n > head->next->n)
			{
				tmp = head;
				node_swap(&tmp, list);
				print_list(*list);
				head = tmp;
			}
			c++;
			head = head->next;
		}
		if (n == 0)
			m = c;
		m--;
		while (head->prev && c >= n)
		{
			if (head->n < head->prev->n)
			{
				tmp = head->prev;
				node_swap(&tmp, list);
				print_list(*list);
				head = tmp->next;
			}
			c--;
			head = head->prev;
		}
	}
}
