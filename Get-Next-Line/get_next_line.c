/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:50:53 by wting             #+#    #+#             */
/*   Updated: 2022/07/08 15:31:00 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trimmer(char *str)
{
	char	*a;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	a = malloc(sizeof(char) * (i + 2));
	if (!a)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		a[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		a[i++] = '\n';
	a[i] = '\0';
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	int			count;
	char		*ret;
	char		*first;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	first = tmp;
	count = read(fd, tmp, BUFFER_SIZE);
	while (count > 0)
	{
		tmp[count] = '\0';
		if (ft_strchr(tmp, '\n'))
		{
			ret = ft_strjoin(buff, trimmer(tmp));
			while (*tmp != '\n')
				++tmp;
			++tmp;
			free (buff);
			buff = ft_strdup(tmp);
			free(first);
			return (ret);
		}
		else if (count == BUFFER_SIZE)
		{
			buff = ft_strjoin(buff, tmp);
			free (tmp);
			tmp = malloc(sizeof(char) * (count + 1));
			count = read(fd, tmp, BUFFER_SIZE);
			first = tmp;
			tmp[count] = '\0';
		}
		else
		{
			ret = ft_strjoin(buff, tmp);
			free (tmp);
			free (buff);
			return (ret);
		}
	}
	if (ft_strchr(buff, '\n'))
	{
		printf("buff: %s", buff);
		ret = trimmer(buff);
		while (*buff != '\n' && *buff)
			++count;
		++count;
		free(tmp);
		tmp = ft_strdup(buff + count);
		free (buff);
		buff = tmp;
		return (ret);
	}
	if (buff)
	{
		tmp = ft_strdup(buff);
		buff = NULL;
		return (tmp);
	}
	free (first);
	return (NULL);
}
