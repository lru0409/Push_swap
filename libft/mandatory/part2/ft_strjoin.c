/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:46 by rolee             #+#    #+#             */
/*   Updated: 2024/03/22 16:27:32 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_strcat(char *dst, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		total_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(total_len + 1);
	if (!new_str)
		return (NULL);
	new_str[0] = 0;
	new_str = ft_strcat(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}

static char	*ft_strcat(char *dst, const char *src)
{
	int	dst_idx;
	int	src_idx;

	dst_idx = 0;
	while (dst[dst_idx])
		dst_idx++;
	src_idx = 0;
	while (src[src_idx])
	{
		dst[dst_idx] = src[src_idx];
		dst_idx++;
		src_idx++;
	}
	dst[dst_idx] = 0;
	return (dst);
}
