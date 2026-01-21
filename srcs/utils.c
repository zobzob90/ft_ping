/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:49:27 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/21 19:03:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	set_socket_timeout(int sockfd, int seconds)
{
	struct timeval timeout;

	timeout.tv_sec = seconds;
	timeout.tv_usec = 0;
	
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
	{
		perror("setsockopt failed\n");
		exit (EXIT_FAILURE);
	}
}
