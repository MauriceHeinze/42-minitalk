/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:39 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/12 09:26:03 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power > 0)
		return (nb * ft_pow(nb, power - 1));
	else
		return (1);
}

int	binary_to_ascii(char *binary)
{
	int	ascii_char;
	int	i;

	ascii_char = 0;
	i = 0;
	while (i < 9)
	{
		if (binary[7 - i] == '1')
			ascii_char = ascii_char + ft_pow(2, i);
		i++;
	}
	return (ascii_char);
}

char	*ascii_to_binary(int c)
{
	int		i;
	char	*binary;

	binary = malloc((sizeof(char) * 9));
	if (!binary)
		return (NULL);
	binary[8] = '\0';
	i = -1;
	while (i++ <= 8)
	{
		// 01000001
		// 01000010
		if (c &(1 << i))
			binary[7 - i] = '1';
		else
			binary[7 - i] = '0';
	}
	return (binary);
}

void	send_char(int pid, int c)
{
	int		i;
	char	*binary;

	binary = malloc((sizeof(char) * 9));
	if (!binary)
		return ;
	binary = ascii_to_binary(c);
	i = 0;
	while (i < 9)
	{
		usleep(50);
		if (binary[i] == '0')
			kill(pid, SIGUSR1);
		else if (binary[i] == '1')
			kill(pid, SIGUSR2);
		i++;
	}
}

void	send_message(int pid, char *message)
{
	size_t	i;
	char	*client_pid;

	i = 0;
	client_pid = ft_itoa(getpid());
	while (i < ft_strlen(message) + 1)
	{
		send_char(pid, message[i]);
		i++;
	}
	i = 0;
	send_char(pid, 2);
	while (i < ft_strlen(client_pid))
	{
		send_char(pid, client_pid[i]);
		i++;
	}
	send_char(pid, 4);
	send_char(pid, 4);
}
