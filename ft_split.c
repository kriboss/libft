/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:55:00 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/19 17:10:15 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(const char *s, char c)
{
	size_t	n;
	int		in;

	n = 0;
	in = 0;
	while (*s)
	{
		if (*s != c && in == 0)
		{
			in = 1;
			n++;
		}
		else if (*s == c)
			in = 0;
		s++;
	}
	return (n);
}

static char	*duping(const char *s, int a, int b)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (b - a + 1));
	if (!str)
		return (NULL);
	while (a < b)
		str[i++] = s[a++];
	str[i] = '\0';
	return (str);
}

static void	free_all(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	inizio;
	size_t	i;
	char	**ptr;
	char	**salva;

	inizio = 0;
	i = 0;
	salva = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!salva || !s)
		return (NULL);
	ptr = salva;
	while (i < ft_strlen(s))
	{
		inizio = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c && i != 0)
		{
			*ptr = duping(s, inizio, i);
			if (!*ptr)
			{
				free_all(salva, ptr - salva);
				return (NULL);
			}
			ptr++;
		}
		i++;
	}
	*ptr = NULL;
	return (salva);
}

#include <stdio.h>

int main()
{
    char str[] = "   ciao  mi chi   kri";
    char delimiter = ' ';
    char **result = ft_split(str, delimiter);
    int i = 0;

    if (!result)
        return (1);

    while (result[i])
    {
        printf("Substring %d: %s\n", i, result[i]);
        i++;
    }
    return (0);
}
