#include "sort.h"

/**
  * swap_nodes - swaps two nodes of a doubly linked list
  * @node: node to swap
  * @list: double linked list head
  * Return: void
  */
void swap_nodes(listint_t **node, listint_t **list)
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
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly-linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *head, *tmp, *tmp2;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	head = *list;
	while (head && head->next)
	{
		if (head->n > head->next->n)
		{
			tmp = head;
			swap_nodes(&tmp, list);
			print_list(*list);
			head = tmp;
			tmp2 = tmp;
			while (tmp2 && tmp2->prev)
			{
				if (tmp2->n < tmp2->prev->n)
				{
					tmp = tmp2->prev;
					swap_nodes(&(tmp), list);
					print_list(*list);
					tmp2 = tmp->next;
				}
				tmp2 = tmp2->prev;
			}
		}
		head = head->next;
	}
}
