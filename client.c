/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:06:36 by maavalya          #+#    #+#             */
/*   Updated: 2024/03/23 14:09:49 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	char_to_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					ident;
	char				*str_to_pass;

	if (argc != 3)
	{
		ft_printf("%s\n", "invalid number of arguments.");
		return (-1);
	}
	ident = ft_atoi(argv[1]);
	str_to_pass = argv[2];
	char_to_bit(ident, str_to_pass, ft_strlen(str_to_pass));
}
