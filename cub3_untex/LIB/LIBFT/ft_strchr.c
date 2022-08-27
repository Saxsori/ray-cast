/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:16:09 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 15:16:16 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)s;
	while (result[i] != '\0' && result[i] != (char) c)
		i++;
	if (result[i] == (char)c)
		return (result + i);
	return (NULL);
}
