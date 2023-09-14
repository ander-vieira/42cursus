/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ander <ander@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:41:47 by ander             #+#    #+#             */
/*   Updated: 2023/09/15 01:43:15 by ander            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTIL_H
# define STRUTIL_H

# include <stdlib.h>

size_t	pf_strlen(char *str);
char	pf_strcontains(char *str, char c);
ssize_t	pf_strfind(char *str, char *charset);

#endif