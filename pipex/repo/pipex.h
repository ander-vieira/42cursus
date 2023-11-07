/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 18:58:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <stdio.h>

typedef struct s_pipex {
	char	*name;
	char	*i_f;
	char	*c_1;
	char	*c_2;
	char	*o_f;
	char	**env;
}	t_pipex;

size_t	px_strlen(char *str);

void	px_putstr(char *str, int fd);

void	px_err_usage(char *pname);
void	px_err_open(char *pname, char *fname);
void	px_err_pipe(char *pname);

void	px_cmd_run(char *cmd, int fdi, int fdo, char **env);

#endif