/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:14:44 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/12 20:54:11 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	const char	n = '\n';

	if (fd >= 0 && s != NULL)
	{
		write(fd, s, ft_strlen(s));
		write(fd, &n, 1);
	}
}
