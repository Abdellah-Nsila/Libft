/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:59 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/30 11:56:17 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	_ft_c_ws(char const *str, char c)
{
	size_t	i;
	size_t	w;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			w++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (w);
}

static void	*_ft_free_words(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

static void	_ft_init_vars_to_zero(size_t *i, size_t *w_i)
{
	*i = 0;
	*w_i = 0;
	return ;
}

static void	_ft_skip(int not, char const *s, size_t *i, char c)
{
	if (not)
		while (*(s + *i) && *(s + *i) != c)
			(*i)++;
	else
		while (*(s + *i) && *(s + *i) == c)
			(*i)++;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*word;
	char	*start;
	size_t	i;
	size_t	w_i;

	_ft_init_vars_to_zero(&i, &w_i);
	strings = (char **)malloc(sizeof(char *) * (_ft_c_ws(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*(s + i))
	{
		_ft_skip(0, s, &i, c);
		if (*(s + i))
		{
			start = (char *)(s + i);
			_ft_skip(1, s, &i, c);
			word = ft_substr(s, start - s, (s + i) - start);
			if (!word)
				return (_ft_free_words(strings));
			strings[w_i++] = word;
		}
	}
	strings[w_i] = 0;
	return (strings);
}

/*int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	strs = ft_split(argv[1], argv[2][0]);
	i = 0;
	while (strs[i])
	{
		printf("string %d: [%s]\n", i, strs[i]);
		i++;
	}
	return (argc);
}
*/