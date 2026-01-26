/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:10:01 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/26 15:48:05 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	print_usage(char *progname)
{
	fprintf(stderr, "Usage: %s [-v] [-?] [-n] [-c count] [-i interval] [-W timeout] <destination>\n", progname);
}

int	parse_arguments(int ac, char *av[], t_ping *ping)
{
	char	*host;
	int		i;

	if (ac < 2)
	{
		print_usage(av[0]);
		return (-1);
	}
	host = NULL;
	i = 1;
	while (i < ac)
	{
		if (strcmp(av[i], "-v") == 0)
			ping->verbose = 1;
		else if (strcmp(av[i], "-n") == 0)
			ping->numeric = 1;
		else if (strcmp(av[i], "-?") == 0)
		{
			print_usage(av[0]);
			exit (0);
		}
		else if (strcmp(av[i], "-c") == 0)
		{
			if (i + 1 >= ac)
			{
				fprintf(stderr, "ft_ping: option requires an argument -- 'c'\n");
				return (-1);
			}
			ping->count = atoi(av[i + 1]);
			if (ping->count <= 0)
			{
				fprintf(stderr, "ft_ping: bad number of packets to transmit.\n");
				return (-1);
			}
			i++;
		}
		else if (strcmp(av[i], "-i") == 0)
		{
			if (i + 1 >= ac)
			{
				fprintf(stderr, "ft_ping: option requires an argument -- 'i'\n");
				return (-1);
			}
			ping->interval = atof(av[i + 1]);
			if (ping->interval < 0.2)
			{
				fprintf(stderr, "ft_ping: bad timing interval.\n");
				return (-1);
			}
			i++;
		}
		else if (strcmp(av[i], "-W") == 0)
		{
			if (i + 1 >= ac)
			{
				fprintf(stderr, "ft_ping: option requires an argument -- 'W'\n");
				return (-1);
			}
			ping->timeout = atoi(av[i + 1]);
			if (ping->timeout <= 0)
			{
				fprintf(stderr, "ft_ping: bad wait time\n");
				return (-1);
			}
			i++;
		}
		else if (av[i][0] == '-')
		{
			fprintf(stderr, "ft_ping: invalid option -- '%s'\n", av[i]);
			print_usage(av[0]);
			return (-1);
		}
		else
			host = av[i];
		i++;
	}
	if (!host)
	{
		fprintf(stderr, "ft_ping: missing host operand\n");
		return (-1);
	}
	resolve_hosts(ping, host);
	ping->hostname = host;
	return (0);
}
