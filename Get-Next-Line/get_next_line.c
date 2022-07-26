/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:50:53 by wting             #+#    #+#             */
/*   Updated: 2022/07/26 13:56:44 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trimmer(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	int			count;
	char		*ret;
	char		*first;
	char		*storage;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	first = tmp;
	count = read(fd, tmp, BUFFER_SIZE);
	while (count > 0)
	{
		tmp[count] = '\0';
		if (ft_strchr(tmp, '\n'))
		{
			storage = trimmer(tmp);
			ret = ft_strjoin(buff, storage);
			free (storage);
			while (*tmp != '\n')
				++tmp;
			++tmp;
			if (buff)
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
			buff = ft_strdup(ret);
			free (ret);
			break;
		}
	}
	if (ft_strchr(buff, '\n'))
	{
		// printf("buff: %s", buff);
		ret = trimmer(buff);
		// printf("%d", count);
		while (buff[count] != '\n')
			++count;
		++count;
		free(tmp);
		tmp = ft_strdup(buff + count);
		free (buff);
		buff = ft_strdup(tmp);
		free (tmp);
		return (ret);
	}
	if (buff)
	{
		free (tmp);
		tmp = ft_strdup(buff);
		free (buff);
		buff = NULL;
		return (tmp);
	}
	free (first);
	return (NULL);
}
