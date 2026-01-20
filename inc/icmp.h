/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:31 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/20 11:56:42 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICMP_H
#define ICMP_H

#include <netinet/ip_icmp.h>

#define ICMP_PACKET_SIZE 64

typedef struct s_icmp_packet
{
	struct icmphdr	header;
	char			payload[ICMP_PACKET_SIZE - sizeof(struct icmphdr)];
} t_icmp_packet;

#endif