/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:00:23 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/20 14:32:10 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

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
