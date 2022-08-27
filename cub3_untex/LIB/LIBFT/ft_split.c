/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:33:27 by aaljaber          #+#    #+#             */
/*   Updated: 2021/10/13 18:24:06 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strn(const char *s, char c)
{
	size_t	nbst;
	size_t	stcnt;

	nbst = 0;
	stcnt = 0;
	while (*s)
	{
		if (*s != c && stcnt == 0)
		{
			stcnt = 1;
			nbst++;
		}
		else if (*s == c)
		{
			stcnt = 0;
		}
		s++;
	}
	return (nbst);
}

static char	*nextstr(const char *str, size_t begin, size_t end)
{
	char	*string;
	size_t	i;

	i = 0;
	string = malloc(sizeof(char) * (end - begin + 1));
	while (begin < end)
	{
		string[i] = str[begin];
		i++;
		begin++;
	}
	string[i] = '\0';
	return (string);
}

static char	**action(char **new, char const *s, char c)
{
	int		start;
	size_t	j;
	size_t	i;
	size_t	ss;

	start = -1;
	i = 0;
	j = 0;
	ss = ft_strlen(s);
	while (i <= ss)
	{
		if (s[i] != c && start < 0)
		{
			start = i;
		}
		else if ((s[i] == c || i == ss) && start >= 0)
		{
			new[j] = nextstr(s, start, i);
			start = -1;
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	nbstr;

	if (!s)
	{
		return (NULL);
	}
	nbstr = strn(s, c);
	new = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (!new)
	{
		return (NULL);
	}
	action(new, s, c);
	return (new);
}
