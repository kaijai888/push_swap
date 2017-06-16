/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_helper4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:59:30 by kzeng             #+#    #+#             */
/*   Updated: 2017/02/04 17:59:32 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_nwords(char const *s, char c, int i)
{
	int				nwords;
	int				begin;
	int				len;

	nwords = 0;
	begin = 0;
	len = ft_checker_strlen(s);
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
	char			*word;
	int				k;

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

char		**ft_checker_strsplit(char const *s, char c)
{
	char			**fresh;
	int				i;
	int				startindex;
	int				endindex;
	int				nwords;

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

char		*ft_checker_strsub(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	k;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL || sub == NULL)
		return (NULL);
	i = ft_checker_strlen(s);
	k = 0;
	while (start < i && k < len)
	{
		sub[k] = s[start];
		k++;
		start++;
	}
	while (k < len + 1)
		sub[k++] = '\0';
	return (sub);
}

char		*ft_checker_strncat(char *s1, char *s2, size_t n)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (n == 0)
		return (s1);
	while (s1[i] != '\0')
		i++;
	while (s2[k] != '\0' && n > 0)
	{
		s1[i] = s2[k];
		i++;
		k++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
