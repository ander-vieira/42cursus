/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:48:44 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 19:12:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# define FT_INT_MAX ((int)2147483647)
# define FT_INT_MIN ((int)-2147483648)

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef unsigned int	t_uint;
typedef int				t_fd;

#endif