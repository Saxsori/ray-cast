/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:13:02 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 15:13:16 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	i = 0;
	src2 = (char *) src;
	dst2 = (char *) dst;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
