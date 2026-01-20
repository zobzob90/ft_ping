/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:57:09 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/20 12:00:21 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	init_ping(t_ping *ping)
{
	if (!ping)
		return ;
	
	memset(ping, 0, sizeof(t_ping));
	
	ping->seq = 0; // compteur de sequence
	ping->transmitted = 0; // paquets envoyes
	ping->received = 0; // paquets recu
	ping->addrlen = sizeof(ping->dest_addr); // taille de l'addresse
}
