/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:17:28 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 15:17:47 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srcl;
	size_t	dstl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (dstl > dstsize)
	{
		dstl = dstsize;
	}
	else if (dstl == dstsize || dstsize == 0)
	{
		return (dstl + srcl);
	}
	else if (srcl < dstsize - dstl)
	{
		ft_memcpy(dst + dstl, src, srcl + 1);
	}
	else
	{
		ft_memcpy(dst + dstl, src, dstsize - dstl - 1);
		dst [dstsize - 1] = '\0';
	}
	return (dstl + srcl);
}
