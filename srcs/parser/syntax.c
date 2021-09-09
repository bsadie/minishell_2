/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:22:20 by eghis             #+#    #+#             */
/*   Updated: 2021/09/09 10:20:18 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_sym(t_list *node)
{
	if (node->pipe == PIPE)
		return ("|");
	if (node->next->sym == AN_BR_R)
		return (">");
	if (node->next->sym == AN_BR_L)
		return ("<");
	if (node->next->sym == AN_BR_R_D)
		return (">>");
	if (node->next->sym == AN_BR_L_D)
		return ("<<");
	return (" ");
}

void	check_syntax(t_all *all)
{
	t_list	*node;

	node = all->commands;
	while (node)
	{
		if (!node->com || !node->com[0])
		{
			all->error = 1;
			if (node->next)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token ",
					STDERR);
				ft_putstr_fd("`", STDERR);
				ft_putstr_fd(find_sym(node), STDERR);
				ft_putstr_fd("\'\n", STDERR);
			}
			else
			{
				if (node->com[0] != '\0')
				{
					ft_putstr_fd("minishell: syntax error near unexpecte", STDERR);
					ft_putstr_fd("d token `newline'\n", STDERR);
				}
			}
			return ;
		}
		node = node->next;
	}
}
