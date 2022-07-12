/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:39 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/11 20:02:05 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

t_stack			g_infos = {0, 1, 0, {0}, {0}};

void	remember_client_pid(int c)
{
	g_infos.client_pid[g_infos.client_pid_counter] = c;
	g_infos.client_pid[g_infos.client_pid_counter + 1] = '\0';
	g_infos.client_pid_counter++;
}

void	write_char(char *binary, int bit)
{
	char	c;

	if (g_infos.counter == 8)
	{
		c = binary_to_ascii(binary);
		g_infos.counter = 0;
		if (c == 2)
			g_infos.print = 0;
		else if (c == 4)
		{
			kill(ft_atoi(g_infos.client_pid), SIGUSR1);
			g_infos.client_pid_counter = 0;
			g_infos.print = 1;
		}
		else if (g_infos.print)
			write(1, &c, 1);
		else if (!g_infos.print && c != 2 && c != 4)
			remember_client_pid(c);
	}
	binary[g_infos.counter] = bit;
	binary[g_infos.counter + 1] = '\0';
	g_infos.counter++;
}

static void	signal_handler_0(int sig)
{
	write_char(g_infos.binary, '0');
}

static void	signal_handler_1(int sig)
{
	write_char(g_infos.binary, '1');
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, signal_handler_0);
	signal(SIGUSR2, signal_handler_1);
	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		usleep(20);
	exit(0);
}
