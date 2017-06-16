/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:38:10 by kzeng             #+#    #+#             */
/*   Updated: 2017/01/31 18:38:11 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			ft_push_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int			ft_push_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nwords(char const *s, char c, int i)
{
	int		nwords;
	int		begin;
	int		len;

	nwords = 0;
	begin = 0;
	len = ft_push_strlen(s);
	while (s[i] != '\0')
	{
		if (begin == 0 && s[i] != c)
		{
			begin = 1;
			nwords++;
		}
		if (i <= len - 1)
		{
			if (begin == 1 && s[i + 1] == c)
				begin = 0;
		}
		i++;
	}
	return (nwords);
}

static char	*ft_word(char const *s, int startindex, int endindex)
{
	char	*word;
	int		k;

	word = (char *)malloc(sizeof(char) * (endindex - startindex + 1));
	if (word == NULL)
		return (NULL);
	k = 0;
	while (startindex < endindex)
	{
		word[k] = s[startindex];
		k++;
		startindex++;
	}
	word[k] = '\0';
	return (word);
}

char		**ft_push_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		startindex;
	int		endindex;
	int		nwords;

	i = 0;
	startindex = 0;
	endindex = 0;
	nwords = ft_nwords(s, c, i);
	if ((fresh = (char **)malloc(sizeof(char *) * (nwords + 1))) == NULL)
		return (NULL);
	while (i < nwords)
	{
		startindex = endindex;
		while (s[startindex] == c)
			startindex++;
		endindex = startindex;
		while (s[endindex] != c && s[endindex] != '\0')
			endindex++;
		if ((fresh[i++] = ft_word(s, startindex, endindex)) == NULL)
			return (NULL);
	}
	fresh[i] = 0;
	return (fresh);
}
