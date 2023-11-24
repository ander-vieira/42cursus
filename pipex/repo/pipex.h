/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:46 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 19:43:38 by andeviei         ###   ########.fr       */
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

# include "libft/libft.h"

# define PATH_PREF	"PATH="
# define PATH_DELIM	'/'
# define ENV_DELIM	':'

typedef int	t_fd;

typedef struct s_cmd {
	char	*cmd;
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_pipex {
	t_bool	here;
	char	*pname;
	char	*infile;
	size_t	cmd_num;
	t_cmd	*cmds;
	char	*outfile;
	char	**env;
}	t_pipex;

void	av_printusage(char *pname);
void	av_printerror(char *pname, char *func, char *msg);

char	**av_getargv(t_pipex *px, size_t i);
void	av_freeargv(char **argv);

t_fd	av_heredoc(t_pipex *px);

t_bool	av_runcmd(t_pipex *px, size_t i);

t_bool	av_initpipex(t_pipex *px, int argc, char **argv, char **envp);
void	av_freepipex(t_pipex *px);

char	*av_getpath(char *cmd, t_pipex *px);

#endif