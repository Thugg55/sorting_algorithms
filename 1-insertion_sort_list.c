#include "sort.h"


/**
 * swap_nodes - function swaps two nodes in a linked list
 * @head: The head of the linked list
 * @node1: The first node
 * @node2: The second node
 */

void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *x;
	listint_t *y;

	x = node1->prev;
	y = node2->next;
	if (x != NULL)
		x->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = y;
	node2->prev = x;
	node2->next = node1;
	if (y != NULL)
		y->prev = node1;
}

/**
 * insertion_sort_list - implements insertion sort algorithm on list
 * @list: Linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *now;
	listint_t *before;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (now = (*list)->next; now && now->prev; now = now->next)
	{
		for (; now && now->prev && now->n < now->prev->n; now = now->prev)
		{
			before = now->prev;
			swap_nodes(list, before, now);
			print_list(*list);
			now = now->next;
		}
	}
}
