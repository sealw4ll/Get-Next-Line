/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:50:53 by wting             #+#    #+#             */
/*   Updated: 2022/08/09 21:25:48 by wting            ###   ########.fr       */
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

char	*nl_found(char **buff)
{
	char		*tmp;
	char		*tmp2;

	tmp = trimmer(*buff);
	tmp2 = ft_strdup(ft_strchr(*buff, '\n') + 1);
	free (*buff);
	*buff = ft_strdup(tmp2);
	free (tmp2);
	return (tmp);
}

static void	reading(int *count, char **buff, int fd)
{
	char	*tmp;
	char	*tmp2;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return ;
	*count = read(fd, tmp, BUFFER_SIZE);
	if (*count < 0)
	{
		free (tmp);
		return ;
	}
	tmp[*count] = 0;
	tmp2 = ft_strdup(*buff);
	free (*buff);
	*buff = ft_strjoin(tmp2, tmp);
	free (tmp2);
	free (tmp);
}

static char	*pp(char **buff, int *count)
{
	char	*tmp;

	if (*count < 0)
		return (NULL);
	if (ft_strchr(*buff, '\n'))
		return (nl_found(&*buff));
	else if (**buff)
	{
		tmp = ft_strdup(*buff);
		free (*buff);
		*buff = NULL;
		return (tmp);
	}
	free (*buff);
	*buff = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	int			count;

	reading(&count, &buff, fd);
	while (count == BUFFER_SIZE)
	{
		if (ft_strchr(buff, '\n'))
			return (nl_found(&buff));
		else
			reading(&count, &buff, fd);
	}
	return (pp(&buff, &count));
}
