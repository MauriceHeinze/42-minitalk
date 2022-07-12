/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mheinze <mheinze@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/06 19:11:49 by mheinze		   #+#	#+#			 */
/*   Updated: 2022/04/22 10:42:09 by mheinze		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler_0(int sig)
{
	write(0, "Message received!\n", 18);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || argv[2][0] == '\0')
		return (0);
	signal(SIGUSR1, signal_handler_0);
	if (argv[1])
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	usleep(500);
	exit(1);
}
