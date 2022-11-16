#include "shell.h"

/**
 * print_list - _print linked list
 * @h: linked list
 * Return: size of linked list
 */
size_t print_list(list_t *h)
{
	list_t *c_list = h;
	int count = 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((c_list->var)[c] != '\0')
				c++;
			write(STDOUT_FILENO, c_list->var, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}

/**
 * add_end_node - add node to end of linked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new linked list
 */
list_t *add_end_node(list_t **head, char *str)
{
	list_t *new;
	list_t *holder;

	if (head == NULL || str == NULL)
		return (NULL); /* check if address of head is null */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->var = _strdup(str);
	new->next = NULL;

	holder = *head;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = new;
	}
	else
	{
		*head = new;
	}
	return (*head);
}

/**
 * delete_nodeint_at_index - removing node at index
 * @head: input head address
 * @index: input index
 * Return: 1 if success, -1 if fail
 */
int delete_nodeint_at_index(list_t **head, int index)
{
	list_t *n_head;
	list_t *holder;
	int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = holder;
		return (1);
	}
	count = 1;
	n_head = *head;
	while (count < index)
	{
		if (n_head == NULL)
			return (-1);
		n_head = n_head->next;
		count++;
	}
	holder = n_head->next;
	n_head->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}

/**
 * free_linked_list - frees linked list
 * @list: linked list
 */
void free_linked_list(list_t *list)
{
	list_t *holder;

	while (list != NULL)
	{
		holder = list;
		list = list->next;
		free(holder->var);
		free(holder);
	}

}
