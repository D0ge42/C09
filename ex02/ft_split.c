/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:56:00 by lorenzo           #+#    #+#             */
/*   Updated: 2024/08/17 17:28:11 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchr(char *str, char c)
{
	while (*str++)
		if (*str == c)
			return (1);
	return (0);
}

int	words_count(char *str, char *charset)
{
	int	words;
	int	i;
	int	in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
		{
			if (!in_word)
			{
				in_word = 1;
				words++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (words);
}

char	*ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = -1;
	while (++i <= len)
		dest[i] = src[i];
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**new;
	char	*start;
	char	*end;
	int		i;

	new = (char **)malloc(sizeof(char *) * (words_count(str, charset) + 1));
	i = 0;
	while (ft_strchr(charset, *str))
		str++;
	start = str;
	while (i < words_count(str, charset))
	{
		end = start;
		while (!ft_strchr(charset, *end))
			end++;
		new[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		ft_strncpy(new[i++], start, end - start - 1);
		while (ft_strchr(charset, *end))
			end++;
		start = end;
	}
	new[i] = 0;
	return (new);
}
