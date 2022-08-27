/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:40:35 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/12 20:36:01 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*nextnode;

	if (!lst || !f)
		return (NULL);
	nextnode = ft_lstnew(f(lst->content));
	if (!nextnode)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	newlst = nextnode;
	lst = lst->next;
	while (lst)
	{
		nextnode = ft_lstnew(f(lst->content));
		if (!nextnode)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlst, del);
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, nextnode);
	}
	return (newlst);
}
