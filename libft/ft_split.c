/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:03:56 by bsamzun           #+#    #+#             */
/*   Updated: 2025/03/20 01:39:39 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	if (s[0] != c && s[0])
		wc++;
	i = -1;
	while (s[++i])
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			wc++;
	return (wc);
}

static char	*worddup(char const *str, char c)
{
	char	*word;
	int		wl;
	int		i;

	wl = 0;
	while (str[wl] && str[wl] != c)
		wl++;
	word = (char *)malloc((wl + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[wl] = '\0';
	i = -1;
	while (++i < wl)
		word[i] = str[i];
	return (word);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split && split[++i])
		free(split[i]);
	if (split)
		free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		wc;
	int		i;
	int		j;

	wc = count_words(s, c);
	split = (char **)malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[wc] = NULL;
	i = 0;
	j = 0;
	while (j < wc)
	{
		while (s[i] == c)
			i++;
		split[j] = worddup(&s[i], c);
		if (!split[j])
			return (ft_free_split(split), NULL);
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (split);
}
