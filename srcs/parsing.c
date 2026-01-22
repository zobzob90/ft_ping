/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:10:01 by ertrigna          #+#    #+#             */
/*   Updated: 2026/01/22 17:27:43 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

void	print_usage(char *progname)
{
	fprintf(stderr, "Usage: %s [-v] [-?] <destination>\n", progname);
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
		else if (strcmp(av[i], "-?") == 0)
		{
			print_usage(av[0]);
			exit (0);
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
