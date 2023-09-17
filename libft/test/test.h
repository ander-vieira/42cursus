/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:22:02 by ander             #+#    #+#             */
/*   Updated: 2023/09/17 15:16:53 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <string.h>

# include "../repo/libft.h"

# define TOTAL_TESTS 1

void	print_test(char *test_id, char result);

char	test_split(void);

#endif