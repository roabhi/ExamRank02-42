/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:53:16 by rabril-h          #+#    #+#             */
/*   Updated: 2022/03/17 18:55:26 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.c"

int	main(void)
{
	char			str[] = "Hello World";
	int				num = -35487;
	unsigned int	hex = 4200;

	int				a;
	int				b;

	printf("======== Strings ======== \n");
	printf("La funcion nativa dice \n");
	a = printf("El valor del string es --> %s <-- \n", str);
	printf("Y su longitud es %d \n", a);
	printf("Mi FT  dice \n");
	b = ft_printf("El valor del string es --> %s <-- \n", str);
	printf("Y su longitud es %d \n", b);

	printf("======== Decimal ======== \n");
	printf("La funcion nativa dice \n");
	a = printf("El valor del decimal es --> %d <-- \n", num);
	printf("Y su longitud es %d \n", a);
	printf("Mi FT  dice \n");
	b = ft_printf("El valor del decimal es --> %d <-- \n", num);
	printf("Y su longitud es %d \n", b);

	printf("======== Hexa ======== \n");
	printf("La funcion nativa dice \n");
	a = printf("El valor del hexa es --> %x <-- \n", hex);
	printf("Y su longitud es %d \n", a);
	printf("Mi FT  dice \n");
	b = ft_printf("El valor del hexa es --> %x <-- \n", hex);
	printf("Y su longitud es %d \n", b);

	
	return (0);
}
