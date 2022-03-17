/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:26:14 by rabril-h          #+#    #+#             */
/*   Updated: 2022/03/15 13:43:05 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	checkdoubles(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *str, char *str2)
{
	int i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str[i] == str2[j])
			{
				if (checkdoubles(str, str[i], i))
				{
					ft_putchar(str[i]);
					break;
				}
			}				
			j++;
		}
		i++;
	}
}

int	main(int i, char **params)
{
	if (i == 3)
		ft_inter(params[1], params[2]);
	ft_putchar('\n');
	return (0);
}
