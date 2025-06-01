/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamzun <bsamzun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:29:29 by bsamzun           #+#    #+#             */
/*   Updated: 2025/05/27 04:19:17 by bsamzun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_strnwlen(const char *str, int mode, int type)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((type == 1 || i < BUFFER_SIZE) && str[i] && str[i] != '\n')
		i++;
	if (!mode)
		return (i);
	else if ((type == 0 && i == BUFFER_SIZE) || !str[i])
		return (0);
	else
		return (1);
}

static	void	update_buf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < BUFFER_SIZE && buf[j] && buf[j] != '\n')
		j++;
	if (!buf[j] || (buf[j] == '\n' && !buf[j + 1]))
	{
		while (i < BUFFER_SIZE)
			buf[i++] = '\0';
	}
	else
	{
		while (++j < BUFFER_SIZE && buf[j])
			buf[i++] = buf[j];
		buf[i] = '\0';
	}
}

static	char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	j = ft_strnwlen(s2, 0, 0);
	if (ft_strnwlen(s2, 1, 0))
		j++;
	if (!s1)
		i = j;
	else
		i = ft_strnwlen(s1, 0, 1) + j;
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[i--] = '\0';
	j--;
	while (j >= 0)
		dst[i--] = s2[j--];
	i++;
	while (--i >= 0)
		dst[i] = s1[i];
	if (s1)
		free(s1);
	update_buf(s2);
	return (dst);
}

static	int	ft_read(char *dst, char *buf, int fd)
{
	int	rc;

	rc = read(fd, buf, BUFFER_SIZE);
	if (rc == -1)
	{
		buf[0] = '\0';
		if (dst)
			free(dst);
	}
	return (rc);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*dst;
	int			rc;

	if (fd > FD_MAX && fd < 0)
		return (NULL);
	dst = NULL;
	if (buf[0])
		dst = ft_gnl_strjoin(dst, buf);
	if (ft_strnwlen(dst, 1, 1))
		return (dst);
	rc = ft_read(dst, buf, fd);
	if (rc == -1 || (!dst && !buf[0]))
		return (NULL);
	while (!ft_strnwlen(buf, 1, 0) && rc == BUFFER_SIZE)
	{
		dst = ft_gnl_strjoin(dst, buf);
		rc = ft_read(dst, buf, fd);
		if (rc == -1)
			return (NULL);
	}
	return (ft_gnl_strjoin(dst, buf));
}
