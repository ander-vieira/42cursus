/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:21 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/14 13:09:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DIRECTIVE_START "%"
# define DIRECTIVE_END "cspdiuxX%"

int	ft_printf(const char *format, ...);

#endif