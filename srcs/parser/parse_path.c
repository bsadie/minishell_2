/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:48:45 by eghis             #+#    #+#             */
/*   Updated: 2021/07/16 18:10:18 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path(t_all *all, int *i, char *path)
{
	char	*path_2;
	int		k;
	int		z;

	z = 0;
	k = *i;
	while (path[*i] && path[*i] != ':')
		*i = *i + 1;
	path_2 = (char *)malloc(sizeof(char) * (*i - k + 1));
	while (k < *i)
		path_2[z++] = path[k++];
	path_2[z] = '\0';
	return (path_2);
}

void	parse_path(t_all *all)
{
	char	*path;
	int		i;
	int		k;

	k = 0;
	i = 0;
	path = ft_strdup(ft_getenv(all, "PATH"));
	if (!path)
		ft_exit(all, "No PATH in Enviroment"); // Подумать над выводом
	while (path[i++])
		if (path[i] == ':')
			k++;
	all->path = (char **)malloc(sizeof(char *) * (k + 2));
	i = 0;
	k = 0;
	while (path[i])
	{
		all->path[k++] = get_path(all, &i, path);
		if (path[i])
			i++;
	}
	all->path[k] = 0;
	free(path);
}
