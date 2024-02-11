/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:23:36 by akizilto          #+#    #+#             */
/*   Updated: 2024/02/05 18:16:05 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (new_str == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			new_str[c] = str[c];
	while (buff[i] != '\0')
		new_str[c++] = buff[i++];
	new_str[c] = '\0';
	free(str);
	return (new_str);
}

char	*read_first_line(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*next_read(char	*str)
{
	int		i;
	int		j;
	char	*nextstr;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	nextstr = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!nextstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		nextstr[j++] = str[i++];
	nextstr[j] = 0;
	free(str);
	return (nextstr);
}
