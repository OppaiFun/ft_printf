/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:02:12 by madamou           #+#    #+#             */
/*   Updated: 2024/05/11 19:13:13 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_moulinette(char *result, unsigned long long int nb, int size,
		char *base)
{
	if (nb >= (unsigned long long int)ft_strlen1(base))
	{
		ft_moulinette(result, nb / ft_strlen1(base), size - 1, base);
		ft_moulinette(result, nb % ft_strlen1(base), size, base);
	}
	if (nb < (unsigned long long int)ft_strlen1(base))
	{
		result[size - 1] = base[nb];
	}
}

char	*ft_itoa_long_long(unsigned long long int nb, char *base)
{
	int		size;
	char	*result;
	int		len_base;

	len_base = ft_strlen1(base);
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
		print = ft_reallocc(print, ft_strlen1(result) + 2);
		if (!print)
			return (free(result), NULL);
		print = ft_strcatt(print, "0x");
		print = ft_strcatt(print, result);
	}
	else
	{
		print = ft_reallocc(print, 5);
		if (!print)
			return (free(result), NULL);
		print = ft_strcatt(print, "(nil)");
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
	if (nb_zero > ft_strlen1(result))
		print = ft_fill_zero1(print, nb_zero, result, sign);
	else
	{
		if (sign == 1)
			print = ft_decimal(print, -nb, 1);
		else
			print = ft_decimal(print, nb, 1);
	}
	return (free(result), print);
}

char	*ft_decimal_zero1(char *print, int nb, int nb_zero)
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
	if (result[0] == '0' && nb_zero == 0)
		return (free(result), print);
	if (nb_zero > ft_strlen1(result) - sign)
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
