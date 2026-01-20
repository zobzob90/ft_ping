/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:40:24 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/20 11:50:55 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
#define PING_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#include <netinet/ip.h>

#include "icmp.h"
#include "utils.h"

typedef struct s_ping
{
	int					sockfd;
	struct sockaddr_in	dest_addr;
	socklen_t			addrlen;
	
	int					seq;
	int					transmitted;
	int					received;
	
	struct timeval		send_time;
} t_ping;

#endif