/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:40:33 by hatalhao          #+#    #+#             */
/*   Updated: 2024/08/08 10:31:16 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

void	free_node(t_node **list, void *ptr)
{
	t_node *iter;

	iter = *list;
	if (ptr == (*list)->allocated)
	{
		// printf("HERE\n");
		*list = (*list)->next;
		free (iter->allocated);
		return free (iter);
	}
	while (iter->allocated != ptr)
		iter = iter->next;
	iter->prev->next = iter->next;
	iter->next->prev = iter->prev;
	free (iter->allocated);
	free (iter);
}

void	free_list(t_node **list)
{
	t_node	*tmp;
	
	if (!list || !*list)
		return ;
	tmp = NULL;
	int i = 0;
	while (*list)
	{
		tmp = *list;
		printf("%d----> %p\n", i++, *list);
		if ((*list)->next)
			*list = (*list)->next;
		free (tmp->allocated);
		free (tmp);
	}
}

t_node	*last_node(t_node *list)
{
	t_node *last;

	if (!list)
		return (NULL);
	last = list;	
	while (list)
	{
		last = list;
		if (!list->next)
			break ;
		list = list->next;
	}
	return (last);
}

void	add_to_tail(t_node **list, t_node *new)
{
	t_node	*last;

	if (!list || !*list)
		*list = new;
	else
	{
		last = last_node(*list);
		last->next = new;
		new->next = NULL;
		new->prev = last;
	}		
}

void	node_allocate(t_node **node, void *ptr)
{
	*node = malloc (sizeof(t_node));
	if (!*node)
		return ;
	(*node)->allocated = ptr;
}

void	ft_malloc(t_node **list, void **ptr, int size, int nmemb)
{
	t_node	*curr;
	
	curr = 0;
	*ptr = malloc (size * nmemb);
	if (!*ptr)
		return ;
	node_allocate(&curr, *ptr);
	add_to_tail(list, curr);
}
