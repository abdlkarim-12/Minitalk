/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenzao <aguenzao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:34:20 by aguenzao          #+#    #+#             */
/*   Updated: 2025/02/04 18:55:36 by aguenzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_new(siginfo_t *info, pid_t *client_pid, int *counter)
{
	if (info->si_pid != *client_pid)
	{
		*client_pid = info->si_pid;
		*counter = 8;
	}
}

void	handle_usr_signals(int SIGUSR, siginfo_t *info, void *vp)
{
	static int				counter;
	static pid_t			client_pid;
	static unsigned char	c;

	(void)vp;
	check_new(info, &client_pid, &counter);
	if (SIGUSR == SIGUSR1)
		c |= 1 << (counter - 1);
	counter--;
	if (counter == 0)
	{
		write(1, &c, 1);
		counter = 8;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_usrs;

	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa_usrs.sa_flags = SA_SIGINFO;
	sa_usrs.sa_sigaction = handle_usr_signals;
	if (sigaction(SIGUSR1, &sa_usrs, NULL) == -1
		|| sigaction(SIGUSR2, &sa_usrs, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
