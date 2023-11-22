/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 16:36:10 by andeviei         ###   ########.fr       */
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

# include "bool.h"

# define PATH_PREF	"PATH="
# define PATH_DELIM	'/'
# define ENV_DELIM	':'

typedef struct s_pipex {
	char	*pname;
	char	*infile;
	char	*c_1;
	char	*c_2;
	char	*outfile;
	char	**env;
}	t_pipex;

size_t	av_strlen(char *str);
t_bool	av_strstarts(char *str, char *pref);
char	*av_strjoin(char *str1, char *str2);

void	av_putstr(char *str, int fd);

void	av_err_usage(char *pname);
void	av_err_func(char *pname, char *func);

char	**av_split(char *str, int space);
void	av_split_free(char **split);

void	av_cmd_run(char *cmd, int *fd, t_pipex *px);

#endif