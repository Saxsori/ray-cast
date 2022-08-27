/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:52:13 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 13:31:22 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;
	unsigned char	a;

	i = 0;
	result = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (result[i] == a)
		{
			return (result + i);
		}
		i++;
	}
	return (NULL);
}
