/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:00:23 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 11:26:17 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	main_running(t_ping *ping, char *av[])
{
	init_ping(ping);
	create_socket(ping);
	resolve_hosts(ping, *av);
	send_ping(ping);
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("Wrong numbers of arguments\n");
		printf("Usage: %s <host>\n", av[0]);
		return (1);
	}

	t_ping ping;
	
	init_ping(&ping);
	create_socket(&ping);
	
	//DEBUG
	printf("Socket ICMP créé avec succès : %d\n", ping.sockfd);
	
	return (0);
}
