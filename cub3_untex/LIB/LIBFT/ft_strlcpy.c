/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:18:19 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 15:18:24 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0' && i < ft_strlen(src))
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	if (dstsize == 0)
		return (ft_strlen(src));
	return (i);
}
