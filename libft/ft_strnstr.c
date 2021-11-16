/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:38:46 by jaekjung          #+#    #+#             */
/*   Updated: 2021/11/16 20:31:17 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlen(char *str);

int	_check(char *str, char *needle, int len, int index)
{
	int	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (str[i] != needle[i])
			return (0);
		i++;
		len--;
	}
	if (index + i >= len)
		return (0);
	return (1);
}


char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	index;

	index = 0;
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	if (*needle == '\0')
		return (haystack);
	while (*haystack && index < len)
	{
		if (*haystack == *needle)
			if (_check(haystack, needle, len, index))
				return (haystack);
		haystack++;
		index++;
	}
	return (0);
}
