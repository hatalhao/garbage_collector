/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:40:04 by hatalhao          #+#    #+#             */
/*   Updated: 2024/08/08 10:26:31 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILES_H
#define UTILES_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_node
{
	void			*allocated;
	struct	s_node	*next;
	struct	s_node	*prev;
}					t_node;


t_node	*last_node(t_node *list);

void	free_list(t_node **list);
void	free_node(t_node **list, void *ptr);
void	node_allocate(t_node **node, void *ptr);
void	add_to_tail(t_node **list, t_node *new);
void	ft_malloc(t_node **list, void **ptr, int size, int nmemb);





#endif