/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:20:25 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/09 17:51:26 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define NEWLINE		"\n"
# define COLON			": "

# define ERR_GENERIC	"Error\n"
# define ERR_USAGE		"Program must have exactly one parameter\n"
# define ERR_EXT		"Argument must have the .ber extension\n"
# define ERR_MAPSTR		"Map doesn't have the correct file structure\n"
# define ERR_OPEN		"open: cannot access file "
# define ERR_READ		"read: cannot read from file "
# define ERR_WRONG_P	"Map doesn't have a single player location\n"
# define ERR_WRONG_C	"Map doesn't have any collectables\n"
# define ERR_WRONG_E	"Map doesn't have a single exit\n"

#endif