/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/07 20:53:18 by andeviei         ###   ########.fr       */
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

# define PATH_PREF	"PATH="
# define PATH_DELIM	'/'
# define ENV_DELIM	':'

typedef struct s_pipex {
	char	*name;
	char	*i_f;
	char	*c_1;
	char	*c_2;
	char	*o_f;
	char	**env;
}	t_pipex;

size_t	px_strlen(char *str);
char	px_strhas(char *str, char c);
char	px_strstarts(char *str, char *pref);
char	*px_strjoin(char *str1, char *str2);

char	**px_split(char *str, int space);
void	px_split_free(char **split);

void	px_putstr(char *str, int fd);

void	px_err_usage(char *pname);
void	px_err_open(char *pname, char *fname);
void	px_err_func(char *pname, char *func);

void	px_cmd_run(char *cmd, int *fd, t_pipex *px);

#endif