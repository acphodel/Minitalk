/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:25:31 by maavalya          #+#    #+#             */
/*   Updated: 2024/03/24 12:04:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	bit_handler(int bit)
{
	static int	byte = 0;
	static int	digit = 0;

	byte += ((bit & 1) << digit);
	digit++;
	if (digit == 7)
	{
		ft_printf("%c", byte);
		if (!byte)
			ft_printf("%c", '\n');
		byte = 0;
		digit = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}
