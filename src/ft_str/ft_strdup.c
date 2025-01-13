/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:29:59 by mgendrot          #+#    #+#             */
/*   Updated: 2025/01/13 13:31:02 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arn_tab_strdup(char *src)
{
	char	*copi;
	int		i;

	i = 0;
	copi = ft_tab_arnalloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copi)
		return (NULL);
	while (src[i])
	{
		copi[i] = src[i];
		i++;
	}
	copi[i] = '\0';
	return (copi);
}

char	*ft_arn_strdup(char *src)
{
	char	*copi;
	int		i;

	i = 0;
	copi = ft_arnalloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copi)
		return (NULL);
	while (src[i])
	{
		copi[i] = src[i];
		i++;
	}
	copi[i] = '\0';
	return (copi);
}

char	*ft_strdup(char *src)
{
	char	*copi;
	int		i;

	i = 0;
	copi = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!copi)
		return (NULL);
	while (src[i])
	{
		copi[i] = src[i];
		i++;
	}
	copi[i] = '\0';
	return (copi);
}
