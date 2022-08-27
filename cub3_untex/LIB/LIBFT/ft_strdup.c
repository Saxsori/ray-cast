/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:11:35 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/12 19:36:47 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	long long	len;
	char		*ret;

	len = 0;
	while (src[len])
	{
		len++;
	}
	ret = (char *)malloc(len + 1);
	if (!ret)
	{
		return (NULL);
	}
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = src[len];
	}
	return (ret);
}
