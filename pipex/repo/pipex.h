/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 21:28:43 by andeviei         ###   ########.fr       */
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
	size_t	cmd_num;
	char	**cmds;
	char	*outfile;
	char	**env;
}	t_pipex;

size_t	av_strlen(char *str);
t_bool	av_strstarts(char *str, char *pref);
void	av_strncpy(char *dst, char *src, size_t len);
t_bool	av_strcmp(char *str1, char *str2);
char	**av_sublist(char **list, size_t len);

void	av_putstr(char *str, int fd);

void	av_printusage(char *pname);
void	av_printerror(char *pname, char *func, char *msg);

char	**av_split(char *str, int space);
void	av_split_free(char **split);

char	*av_getpath(char *cmd, t_pipex *px);

#endif