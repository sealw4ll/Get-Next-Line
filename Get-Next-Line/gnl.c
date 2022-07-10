/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:33:56 by wting             #+#    #+#             */
/*   Updated: 2022/07/06 16:59:08 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// static char	*trimmer(char *str)
// {
// 	char	*a;
// 	int		i;

// 	i = 0;
// 	while (str[i] != '\n')
// 		++i;
// 	a = malloc(sizeof(char) * (i + 2));
// 	if (!a)
// 		return NULL;
// 	i = 0;
// 	while (str[i] != '\n')
// 	{
// 		a[i] = str[i];
// 		i++;
// 	}
// 	a[i++] = '\n';
// 	a[i] = '\0';
// 	return (a);
// }

// void	gnl(int fd)
// {
// 	static char *buff;
// 	int			count;
// 	char		*tmp;

// 	count = read(fd, tmp, BUFFER_SIZE);
// 	// printf("%s", tmp);
// 	tmp[count + 1] = '\0';
// 	printf("%s", tmp);
// 	// printf("%i", count);
// 	// return(tmp);
// }