/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:50:48 by aaljaber          #+#    #+#             */
/*   Updated: 2022/07/30 22:13:47 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_height(t_map *m_info)
{
	char	*line;

	m_info->fd = open(m_info->m_name, O_RDONLY);
	line = get_next_line(m_info->fd);
	m_info->size.width = ft_strlen(line);
	if (line)
		m_info->size.height++;
	line = get_next_line(m_info->fd);
	while (line)
	{
		m_info->size.height++;
		line = get_next_line(m_info->fd);
	}
	close(m_info->fd);
}

char	*no_newline(char *line)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (ft_strlen(line) - 1));
	i = -1;
	while (line[++i] != '\n' && line[i])
		new[i] = line[i];
	new[i] = '\0';
	return (new);
}

void	get_map(t_map *m_info)
{
	int		i;

	get_height(m_info);
	m_info->map = (char **)malloc(sizeof(char *) * m_info->size.height + 1);
	m_info->map[m_info->size.height] = NULL;
	m_info->map_dimn = (int *)malloc(sizeof(int) * m_info->size.height);
	i = -1;
	m_info->fd = open(m_info->m_name, O_RDONLY);
	while (++i < m_info->size.height)
	{
		m_info->map[i] = no_newline(get_next_line(m_info->fd));
		m_info->map_dimn[i] = ft_strlen(m_info->map[i]);
	}
	close(m_info->fd);
}

void	print_map(t_map *m_info)
{
	int	i;

	i = -1;
	while (m_info->map[++i])
		printf("%s\n", m_info->map[i]);
}