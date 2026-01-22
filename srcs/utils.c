/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:49:27 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 17:35:18 by ertrigna         ###   ########.fr       */
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

void	print_stat(t_ping *ping)
{
	int		lost;
	float	loss_percent;	
	printf("\n--- %s ping statistics ---\n", ping->hostname);
	lost = ping->transmitted - ping->received;
	loss_percent = 0.0;
	if (ping->transmitted > 0)
		loss_percent = ((float)lost / (float)ping->transmitted) * 100.0;
	printf("%d packets transmitted, %d packets received, %.1f%% packet loss\n", ping->transmitted, ping->received, loss_percent);
}