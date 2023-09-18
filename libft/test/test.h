/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:22:02 by ander             #+#    #+#             */
/*   Updated: 2023/09/18 00:52:36 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# include "../../test/testutils.h"

# include "libft.h"

# define TMP_FD "tmp_fd"

void	test_is(void);
void	test_to(void);
void	test_mem(void);
void	test_str(void);
void	test_split(void);
void	test_atoi(void);
void	test_fd(void);
void	test_bonus(void);

#endif