/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:57:09 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/20 15:41:41 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	init_ping(t_ping *ping)
{
	if (!ping)
		return ;
	
	memset(ping, 0, sizeof(t_ping));
	
	ping->seq = 0; 								// compteur de sequence
	ping->transmitted = 0;						// paquets envoyes
	ping->received = 0; 						// paquets recu
	ping->addrlen = sizeof(ping->dest_addr);	// taille de l'addresse
}

void	init_tcmp_packet(t_icmp_packet *packet, int seq)
{
	struct timeval tv;
	
	if (!packet)
		return ;
	
	memset(packet, 0, sizeof(t_icmp_packet));

	packet->header.type = ICMP_ECHO;
	packet->header.code = 0;
	packet->header.un.echo.id = htons(getpid());
	packet->header.un.echo.sequence = htons(seq);

	gettimeofday(&tv, NULL);
	memcpy(packet->payload, &tv, sizeof(tv));
}
