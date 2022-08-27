/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:25:30 by aaljaber          #+#    #+#             */
/*   Updated: 2021/11/01 19:14:58 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   GET_NEXT_LINE_BONUS_H
# define  GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);

#endif
