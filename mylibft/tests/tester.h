/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:10:24 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/05 21:02:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <string.h>

# include "../libft/libft.h"

# define COLOR_GREEN	"\033[0;32m"
# define COLOR_NONE		"\033[0m"
# define COLOR_RED		"\033[0;31m"

void	print_title(char *title);
void	print_test(char *text, t_bool ok, t_bool last);
int		print_all_tests(void);

void	test_misc(void);
void	test_str1(void);
void	test_str2(void);
void	test_str3(void);
void	test_gnl(void);
void	test_print(void);
void	test_printf(void);
void	test_path(void);

#endif