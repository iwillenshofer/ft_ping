/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping_mac.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:21:59 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/14 11:26:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_MAC_H
# define FT_PING_MAC_H

/*
** file to determine platform-specific variables making the code compilable
** both for Mac and linux.
** Developed using Catalina (10.15.7) and Debian Wheeler (7.11)
*/


# define SOCKET_DOMAIN AF_INET
# define SOCKET_TYPE SOCK_DGRAM
# define SOCKET_PROTOCOL IPPROTO_ICMP

#endif
