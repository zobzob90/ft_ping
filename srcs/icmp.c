/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:17:56 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 15:39:44 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

uint16_t icmp_checksum(void *data, int len)
{
	uint16_t	*buf;
	uint32_t	sum;
	
	if (!data || len < 0)
		return (0);
	buf = data;
	sum = 0;
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

ssize_t recv_packet(t_ping *ping, uint8_t *buffer, size_t size)
{
	struct sockaddr_in	addr;
	socklen_t			addrlen = sizeof(addr);
	ssize_t				bytes = recvfrom(ping->sockfd, buffer, size, 0, (struct sockaddr *)&addr, &addrlen);
	
	if (bytes < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
			return (0);
		perror("recvfrom() failed");
		return (-1);
	}
	
	return (bytes);
}

int	parse_packet(t_ping *ping, uint8_t *buf, ssize_t len)
{
	struct iphdr	*ip_hdr;
	struct icmphdr	*icmp_hdr;
	int				ip_len;

	if (len < (ssize_t)(sizeof(struct iphdr) + sizeof(struct icmphdr)))
		return (-1);
	ip_hdr = (struct iphdr *)buf;
	ip_len = ip_hdr->ihl * 4;
	if (len < (ssize_t)(ip_len + sizeof(struct icmphdr)))
		return (-1);
	icmp_hdr = (struct icmphdr *)(buf + ip_len);
	return (parse_icmp(ping, buf + ip_len, len - ip_len, icmp_hdr->un.echo.sequence));
	
}

int	parse_icmp(t_ping *ping, uint8_t *packet, ssize_t len, int seq)
{
	t_icmp_packet *icmp_packet;

	if (!ping || !packet || len < (ssize_t)sizeof(t_icmp_packet))
		return (-1);
	icmp_packet = (t_icmp_packet *)packet;
	if (icmp_packet->header.type != ICMP_ECHOREPLY)
		return (-1);
	if (ntohs(icmp_packet->header.un.echo.id) != getpid())
		return (-1);
	if (ntohs(icmp_packet->header.un.echo.sequence) != seq)
		return (-1);
	return (handle_echo_reply(ping, packet, len, seq));
}

int	handle_echo_reply(t_ping *ping, uint8_t *packet, ssize_t len, int seq)
{
	t_icmp_packet	*icmp_packet;
	struct timeval	sentime;
	struct timeval	now;
	long			rtt_ms;
	
	if (!ping || !packet || len < (ssize_t)sizeof(t_icmp_packet))
		return (-1);
	icmp_packet = (t_icmp_packet *)packet;
	memcpy(&sentime, icmp_packet->payload, sizeof(struct timeval));
	gettimeofday(&now, NULL);
	rtt_ms = (now.tv_sec - sentime.tv_sec) * 1000 + (now.tv_usec - sentime.tv_usec) / 1000;
	ping->received++;
	printf("%ld bytes from %s: icmp_seq=%d time=%ld ms\n", len, inet_ntoa(ping->dest_addr.sin_addr), seq, rtt_ms);
	return (0);
}
