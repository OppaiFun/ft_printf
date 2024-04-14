/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:02:12 by madamou           #+#    #+#             */
/*   Updated: 2024/04/14 03:35:36 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_moulinette(char *result, unsigned long long int nb, int size,
		char *base)
{
	if (nb >= (unsigned long long int)ft_strlen(base))
	{
		ft_moulinette(result, nb / ft_strlen(base), size - 1, base);
		ft_moulinette(result, nb % ft_strlen(base), size, base);
	}
	if (nb < (unsigned long long int)ft_strlen(base))
	{
		result[size - 1] = base[nb];
	}
}

char	*ft_itoa_long_long(unsigned long long int nb, char *base)
{
	int		size;
	char	*result;
	int		len_base;

	len_base = ft_strlen(base);
	size = ft_size_malloc_long(nb, len_base);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_moulinette(result, nb, size, base);
	result[size] = '\0';
	return (result);
}

char	*ft_pointer(char *print, void *ptr)
{
	unsigned long long int	true_ptr;
	char					*result;
	char					*base;

	base = "0123456789abcdef";
	true_ptr = (unsigned long long int)ptr;
	result = ft_itoa_long_long(true_ptr, base);
	if (!result)
		return (NULL);
	if (true_ptr != 0)
	{
		print = ft_realloc(print, ft_strlen(result) + 2);
		if (!print)
			return (free(result), NULL);
		print = ft_strcat(print, "0x");
		print = ft_strcat(print, result);
	}
	else
	{
		print = ft_realloc(print, 5);
		if (!print)
			return (free(result), NULL);
		print = ft_strcat(print, "(nil)");
	}
	return (free(result), print);
}

char	*ft_decimal_zero(char *print, int nb, int nb_zero)
{
	char	*result;
	int		sign;

	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	result = ft_itoa(nb);
	if (!result)
		return (NULL);
	if (ft_strlen(result) < nb_zero)
		print = ft_fill_zero(print, nb_zero, result, sign);
	else
	{
		if (sign == 1)
			print = ft_decimal(print, -nb, 1);
		else
			print = ft_decimal(print, nb, 1);
	}
	return (free(result), print);
}

char	*ft_hexa_lowercase_zero(char *print, unsigned int nb, int nb_zero)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789abcdef";
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (len_result < nb_zero)
	{
		print = ft_realloc(print, nb_zero);
		if (!print)
			return (free(result), NULL);
		while (nb_zero-- > len_result)
			print = ft_strcat(print, "0");
		print = ft_strcat(print, result);
	}
	else
		print = ft_hexa_lowercase(print, nb, 1);
	return (free(result), print);
}
