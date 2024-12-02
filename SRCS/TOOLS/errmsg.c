/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmsg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:25:59 by pmateo            #+#    #+#             */
/*   Updated: 2024/12/02 19:31:31 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*__append_strs(char *s1, char *s2)
{
	char	*tmp;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (yama(ADD, ft_strdup(s2), 0));
	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	secure_malloc(s1, true);
	(void)yama(ADD, s1, 0);
	return (s1);
}

void	err_msg(char *detail, char *reason)
{
	char	*msg;

	msg = NULL;
	if (detail != NULL)
	{
		msg = __append_strs(__append_strs(NULL, ERR), detail);
		msg = __append_strs(msg, ": ");
		msg = __append_strs(msg, reason);
	}
	else
		msg = __append_strs(__append_strs(NULL, ERR), reason);
	ft_putendl_fd(msg, STDERR_FILENO);
	yama(REMOVE, msg, 0);
}

int	err_msg_cmd(char *cmd, char *detail, char *reason, int err_no)
{
	char	*msg;

	msg = NULL;
	if (cmd != NULL)
	{
		msg = __append_strs(__append_strs(NULL, ERR), cmd);
		msg = __append_strs(msg, ": ");
	}
	if (detail != NULL)
	{
		msg = __append_strs(msg, detail);
		msg = __append_strs(msg, ": ");
	}
	msg = __append_strs(msg, reason);
	ft_putendl_fd(msg, STDERR_FILENO);
	yama(REMOVE, msg, 0);
	return (err_no);
}
