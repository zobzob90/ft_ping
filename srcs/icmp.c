/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:17:56 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/21 18:47:22 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

uint16_t icmp_checksum(void *data, int len)
{
	if (!data || len < 0)
		return (0);
	uint16_t *buf = data;
	uint32_t sum = 0;
	
	while (len > 1)
	{
		sum += *buf++;
		len -= 2;
	}
	if (len == 1)
		sum += *(uint8_t *)buf;
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	return ((uint16_t)(~sum));
}
