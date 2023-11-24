/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:30 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/24 16:07:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ERR_PARSENUM_OK		0
# define ERR_PARSENUM_BADBASE	1
# define ERR_PARSENUM_BADCHAR	2
# define ERR_PARSENUM_OVERFLOW	3

typedef unsigned char	t_error;

#endif