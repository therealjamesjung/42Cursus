/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:52:05 by jaekjung          #+#    #+#             */
/*   Updated: 2021/11/08 16:52:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char *ft_strdup(char *src)
{
	int i;
	char *dup_str;

	dup_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup_str == NULL)
		return (0);
	i = -1;
	while (src[++i] != '\0')
		dup_str[i] = src[i];
	dup_str[i] = '\0';
	return (dup_str);
}
