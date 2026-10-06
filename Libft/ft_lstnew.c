/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:42:29 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/01 18:06:38 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node_ptr;

	new_node_ptr = (t_list *)malloc(sizeof(t_list));
	if (!new_node_ptr)
		return (NULL);
	new_node_ptr->content = content;
	new_node_ptr->next = NULL;
	return (new_node_ptr);
}
