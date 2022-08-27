/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:25:30 by aaljaber          #+#    #+#             */
/*   Updated: 2022/07/14 00:28:53 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 100

char		*gnl_strjoin(char *s1, char *s2);
char		*gnl_strchr(char *s, int c);
char		*get_next_line(int fd);
size_t		gnl_strlen(char *s);

#endif
