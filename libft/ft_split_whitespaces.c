/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:04:40 by jvitry            #+#    #+#             */
/*   Updated: 2017/11/17 12:50:54 by jvitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int		ft_change_separator(char *str)
{
	int		words;
	int		i;
	int		nb;

	words = 0;
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			str[i] = '\0';
		if (str[i] == '\0' && (str[i - 1] != '\0'))
			words++;
		i++;
	}
	if (str[i - 1] != ' ' && str[i - 1] != '\0')
		words++;
	return (words);
}

static char		*ft_strdup(char *src)
{
	char	*str;
	int		s;
	int		i;

	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	str = (char*)malloc(sizeof(*str) * (s) + 1);
	while (i <= s)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void		ft_extract_words(char *str, char **tab, int count)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	while (count != 0)
	{
		count--;
		while (str[i] == '\0')
			i++;
		k = 0;
		while (str[i + k])
			k++;
		tab[j] = malloc(sizeof(char) * (k + 1));
		k = 0;
		while (str[i])
			tab[j][k++] = str[i++];
		tab[j][k] = 0;
		j++;
	}
	tab[j] = 0;
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	char	*str_copy;
	int		count;

	str_copy = ft_strdup(str);
	count = ft_change_separator(str_copy);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	ft_extract_words(str_copy, tab, count);
	return (tab);
}
