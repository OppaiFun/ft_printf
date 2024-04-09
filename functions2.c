/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:27:18 by madamou           #+#    #+#             */
/*   Updated: 2024/04/09 06:26:52 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_realloc(char *print, int len_realloc)
{
	char	*tmp;
	int		i;

	i = ft_strlen(print);
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	tmp = ft_strcpy(tmp, print);
	free(print);
	print = malloc(sizeof(char) * (i + len_realloc + 1));
	if (!print)
		return (free(tmp), NULL);
	print = ft_strcpy(print, tmp);
	free(tmp);
	return (print);
}

char	*ft_string(char *print, char *str)
{
	print = ft_realloc(print, ft_strlen(str));
	if (!print)
		return (NULL);
	print = ft_strcat(print, str);
	return (print);
}

char	*ft_unsigned(char *print, unsigned int nb)
{
	char	*result;
	int		len_result;

	result = ft_itoa_unsigned(nb);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	print = ft_realloc(print, len_result);
	if (!print)
		return (NULL);
	print = ft_strcat(print, result);
	return (free(result), print);
}

char	*ft_hexa_lowercase(char *print, unsigned int nb, int cas)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789abcdef";
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (cas == 1)
		print = ft_realloc(print, len_result);
	if (cas == 2)
		print = ft_realloc(print, len_result + 2);
	if (!print)
		return (NULL);
	if (cas == 2)
		print = ft_strcat(print, "0x");
	print = ft_strcat(print, result);
	return (free(result), print);
}

char	*ft_hexa_uppercase(char *print, unsigned int nb, int cas)
{
	char	*result;
	int		len_result;
	char	*base;

	base = "0123456789ABCDEF";
	result = ft_itoa_base(nb, base);
	if (!result)
		return (NULL);
	len_result = ft_strlen(result);
	if (cas == 1)
		print = ft_realloc(print, len_result);
	if (cas == 2)
		print = ft_realloc(print, len_result + 2);
	if (!print)
		return (NULL);
	if (cas == 2)
		print = ft_strcat(print, "0X");
	print = ft_strcat(print, result);
	return (free(result), print);
}
