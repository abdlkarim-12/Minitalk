/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenzao <aguenzao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:33:56 by aguenzao          #+#    #+#             */
/*   Updated: 2025/02/07 19:14:23 by aguenzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(unsigned char s, int server_pid)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (s & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	int					server_pid;
	int					i;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid < 1 || kill(server_pid, 0) == -1)
		{
			write(1, "Invalid PID\n", 12);
			return (0);
		}
		i = 0;
		while (av[2][i])
		{
			send_sig((unsigned char)av[2][i], server_pid);
			i++;
		}
		send_sig('\n', server_pid);
	}
	else
		write(1, "Usage: ./client [server_pid] [message]\n", 39);
	return (0);
}
