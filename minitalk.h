/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:05:26 by mheinze           #+#    #+#             */
/*   Updated: 2022/07/11 20:14:09 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_stack
{
	int		counter;
	int		print;
	int		client_pid_counter;
	char	client_pid[10];
	char	binary[1024];
}	t_stack;

int		ft_pow(int nb, int power);
void	send_message(int pid, char *message);
void	send_char(int pid, int c);
char	*ascii_to_binary(int c);
int		binary_to_ascii(char *binary);

int		ft_atoi(const char *nptr);
char	*ft_itoa(int nbr);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
