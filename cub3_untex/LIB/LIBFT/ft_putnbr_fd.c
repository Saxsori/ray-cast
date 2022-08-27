/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:16:59 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/12 18:17:51 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	new_nb;

	if (n == 0)
	{
		ft_putchar_fd (n + 48, fd);
	}
	else if (n > 0)
	{
		new_nb = n / 10;
		if (new_nb != 0)
		{
			ft_putnbr_fd(new_nb, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		new_nb = 0 - (n / 10);
		if (new_nb != 0)
		{
			ft_putnbr_fd(new_nb, fd);
		}
		ft_putchar_fd(0 - (n % 10) + 48, fd);
	}
}
