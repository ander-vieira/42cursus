/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:43:44 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/22 21:10:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_H
# define TESTUTILS_H

# include <stdio.h>

# define COLOR_R	"\033[0;31m"
# define COLOR_G	"\033[0;32m"
# define COLOR_NO	"\033[0m"

void	print_test(char *test_id, char result);
void	print_all_tests(void);

#endif