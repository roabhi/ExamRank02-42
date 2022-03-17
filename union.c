/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:47:35 by rabril-h          #+#    #+#             */
/*   Updated: 2022/03/15 12:31:07 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	clear_last_doubles(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}	
	return (1);
}

int	clear_doubles(char *str, char c, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{

		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *str_1, char *str_2 )
{
	int i;

	i = 0;
	while (str_1[i])
	{
		if (clear_doubles(str_1, str_1[i], i))
			ft_putchar(str_1[i]);
		i++;
	}
	//printf("\n\n");
	i = 0;
	while (str_2[i])
	{
		if (clear_last_doubles(str_1, str_2[i]))
		{
			if (clear_doubles(str_2, str_2[i], i))
				ft_putchar(str_2[i]);
		}			
		i++;
	}
}


int	main(int i, char **params)
{

	if (i == 3)
		ft_union(params[1], params[2]);
	else
		//printf("Argumentos incorrectos");
	write(1, "\n", 1);
	return (0);
}
