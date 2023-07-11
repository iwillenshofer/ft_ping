/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:42:53 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/11 16:42:00 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this file sets up the ft_ping structure.
*/

#include "ft_ping.h"

/*
**
*/
char	**parse_options(t_ping *ft_ping, char **argv)
{
	char *s;

	(void)ft_ping;
	s = ++(*argv);
	while (*s)
	{
		if (*s == 'h')
		{
			print_usage(ft_ping);
			exit(0);
		}
		else if (*s == 'v')
		{
			printf("SETTING VERBOSE\n");
		}
		else
		{
			printf("invalid option -- '%c'\n", *s);
			print_usage(ft_ping);
			exit(0);
		}
		s++;
	}
	return (argv);
}

void	parse(t_ping *ft_ping, char **argv)
{
	char *host;
	host = NULL;
	ft_ping->program = *argv;
	if (ft_arglen(argv) == 1)
		fatal(ft_ping, NULL, true);
	argv++;
	while (argv && *argv)
	{
		if (**argv == '-')
			argv = parse_options(ft_ping, argv);
		else
		{
			if (host)
				fatal(ft_ping, get_errorstr(ft_ping, ERROR_INVALID_ARGUMENTS, ft_ping->program, *argv), true);
			host = *argv;
		}
		if (argv)
			argv++;
	}
	if (!host)
		fatal(ft_ping, get_errorstr(ft_ping, ERROR_INVALID_ARGUMENTS, ft_ping->program, NULL), true);
	ft_ping->raw_host = host;
}

void	set_defaults(t_ping *ft_ping)
{
	(void)ft_ping;
}

void	setup(t_ping *ft_ping, char **argv)
{
	ft_bzero(ft_ping, sizeof(t_ping));
	parse(ft_ping, argv);
	ft_ping->pid = getpid();
	set_defaults(ft_ping);
}