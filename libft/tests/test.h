/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:22:02 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 20:13:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# include "testutils.h"

# include "../repo/libft.h"

void	test_is(void);
void	test_to(void);
void	test_mem(void);
void	test_str(void);
void	test_striter(void);
void	test_split(void);
void	test_atoi(void);
void	test_fd(void);
void	test_lst(void);
void	test_lstiter(void);

#endif