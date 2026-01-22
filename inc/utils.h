/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:29 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 17:35:27 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

void	set_socket_timeout(int sockfd, int seconds); // defini le timeout du socket
void	print_usage(char *progname);
int		parse_arguments(int ac, char *av[], t_ping *ping);
void	print_stat(t_ping *ping);

#endif