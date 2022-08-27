/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:57:57 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/12 20:02:57 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		cc;

	i = 0;
	cc = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			cc = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	else if (cc == -1)
		return (NULL);
	else
		return ((char *)s + cc);
}
