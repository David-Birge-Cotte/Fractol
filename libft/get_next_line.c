/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:31:25 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/12/01 11:31:26 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** get_next_line(const int fd, char **line)
** returns 1 when a line has been read
** returns 0 when reading is finished
** returns -1 if an error occured
*/

static int	ft_occurence_nl(const char *s)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_line_from_list(t_list **lst, size_t fd, char *line)
{
	char	*tmp;
	int		lbi;
	int		rest;
	t_list	*elem;

	elem = *lst;
	while (elem)
	{
		if (elem->content_size != fd)
			elem = elem->next;
		else
			break ;
	}
	if (!elem || elem->content_size != fd)
		return (NULL);
	if ((lbi = ft_occurence_nl((char*)elem->content)) == -1)
		return (NULL);
	tmp = ft_strdup((char*)elem->content);
	line = ft_strncpy(ft_strnew(lbi), tmp, lbi);
	rest = ft_strlen(tmp) - ft_strlen(line);
	ft_strdel(&tmp);
	tmp = ft_strncpy(ft_strnew(rest), (char*)&elem->content[lbi + 1], rest - 1);
	ft_memdel(&(elem->content));
	elem->content = tmp;
	return (line);
}

static void	add_data_to_list(t_list **lst, char *data, size_t fd)
{
	t_list	*elem;
	char	*str_tmp;

	elem = *lst;
	while (elem)
	{
		if (elem->content_size != fd)
			elem = elem->next;
		else
			break ;
	}
	if (!elem || elem->content_size != fd)
	{
		ft_lstadd(lst, ft_lstnew((void*)data, BUFF_SIZE));
		(*lst)->content_size = fd;
	}
	else
	{
		str_tmp = (void*)ft_strjoin((char*)elem->content, data);
		if (elem->content != NULL)
			ft_memdel(&(elem->content));
		elem->content = str_tmp;
	}
}

static char	*get_end_of_file(t_list **lst, size_t fd)
{
	char	*line;

	line = NULL;
	while (*lst)
	{
		if ((*lst)->content_size != fd)
			*lst = (*lst)->next;
		else
			break ;
	}
	if (!*lst || (*lst)->content_size != fd)
		return (NULL);
	if ((*lst)->content)
	{
		line = ft_strdup((*lst)->content);
		ft_memdel(&((*lst)->content));
	}
	ft_memdel((void**)lst);
	if (line && line[0] != '\0')
		return (line);
	ft_strdel(&line);
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				r;
	char			buf[BUFF_SIZE + 1];

	if (!line)
		return (-1);
	while (1)
	{
		*line = get_line_from_list(&lst, (size_t)fd, *line);
		if (*line)
			return (1);
		else if ((r = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[r] = '\0';
			add_data_to_list(&lst, buf, (size_t)fd);
		}
		else if (r == -1)
			return (-1);
		else if ((*line = get_end_of_file(&lst, (size_t)fd)))
			return (1);
		else
			return (0);
	}
}
