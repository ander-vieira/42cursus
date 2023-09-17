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

# include <stdio.h>
# include <string.h>

# include "../repo/libft.h"

void	print_test(char *test_id, char result);

void	test_is(void);
void	test_to(void);
void	test_mem(void);
void	test_split(void);

#endif