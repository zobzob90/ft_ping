/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:00:23 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 15:32:30 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

int main(int ac, char *av[])
{
	t_ping 	ping;
	uint8_t	buffer[1024];
	ssize_t	bytes;
	
	if (ac != 2)
	{
		printf("Wrong numbers of arguments\n");
		printf("Usage: %s <host>\n", av[0]);
		return (1);
	}	
	init_ping(&ping);
	resolve_hosts(&ping, av[1]);
	create_socket(&ping);
	while (1)
	{
		send_ping(&ping);
		bytes = recv_packet(ping, buffer, sizeof(buffer));
		if (bytes > 0)
			parse_packet(&ping, buffer, bytes);
		else if (bytes == 0)
			printf("Request timeout for icmp_seq %d\n", ping.seq);
		ping.seq++;
		ping.transmitted++;
		sleep(1);
	}
	return (0);
}
