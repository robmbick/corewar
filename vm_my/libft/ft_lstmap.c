/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:58:45 by bnetschu          #+#    #+#             */
/*   Updated: 2018/10/31 15:12:05 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	list = f(lst);
	begin = list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = f(lst);
		list = list->next;
	}
	return (begin);
}
