/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <edgghaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:27:55 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/18 13:08:53 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*v;
	int		i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	v = (char *) malloc(i + 1);
	if (!v)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
	{
		v[i] = s[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}

char	*ft_strdup_env(const char *s)
{
	char	*v;
	int		i;

	i = 0;
	v = malloc (sizeof (*v) * (ft_strlen(s) + 1));
	if (!v)
		return (NULL);
	while (s && s[i])
	{
		v[i] = s[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}
