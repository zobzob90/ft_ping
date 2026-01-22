/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:00:23 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 17:34:29 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

volatile sig_atomic_t g_signal = 0;

void	signal_handler(int sig)
{
	(void)sig;
	g_signal = 1;
}

int main(int ac, char *av[])
{
	t_ping 	ping;
	uint8_t	buffer[1024];
	ssize_t	bytes;
	
	init_ping(&ping);
	if (parse_arguments(ac, av, &ping) < 0)
		return (1);
	create_socket(&ping);
	printf("PING %s (%s): 56 data bytes\n", ping.hostname, inet_ntoa(ping.dest_addr.sin_addr));
	while (!g_signal)
	{
		send_ping(&ping);
		bytes = recv_packet(&ping, buffer, sizeof(buffer));
		if (bytes > 0)
			parse_packet(&ping, buffer, bytes);
		else if (bytes == 0)
			printf("Request timeout for icmp_seq %d\n", ping.seq);
		sleep(1);
	}
	if (g_signal)
		print_stat(&ping);
	close(ping.sockfd);
	return (0);
}
