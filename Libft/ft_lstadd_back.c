/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:19:19 by sarakely          #+#    #+#             */
/*   Updated: 2026/10/06 16:37:33 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* 
my solution
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*add;

	add = ft_lstlast(*lst);
	if (!add)
		*lst = add;
	else
		add->next = new;
	ft_lstnew(add);
}
*/
