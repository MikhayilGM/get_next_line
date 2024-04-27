/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhmart <mikhmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:43:41 by mikhmart          #+#    #+#             */
/*   Updated: 2024/04/27 17:55:32 by mikhmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*get_result(char *file)
{
	char	*result;
	int		i;

	i = 0;
	if (!file || !*file)
		return (0);
	while (file[i] != '\0' && file[i] != '\n')
		++i;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (0);
	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
	{
		result[i] = file[i];
		++i;
	}
	if (file[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*shrink_dest(char *file)
{
	char	*result;
	int		i;
	int		size;

	i = 0;
	if (!file)
		return (0);
	while (file[i] != '\0' && file[i] != '\n')
		++i;
	if (!file[i])
		return (ft_free(file));
	if (file[i++] == '\0')
		return (NULL);
	size = ft_strlen(file) - i;
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (ft_free(file));
	size = 0;
	while (file[i])
		result[size++] = file[i++];
	result[size] = '\0';
	free(file);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		lt[BUFFER_SIZE + 1];
	int			buf_was_read;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		buf_was_read = read(fd, lt, BUFFER_SIZE);
		if (buf_was_read <= 0)
			break ;
		lt[buf_was_read] = '\0';
		file = ft_strjoin(file, lt);
		if (ft_strchr(lt, '\n'))
			break ;
	}
	if (buf_was_read < 0)
		return (0);
	result = get_result(file);
	file = shrink_dest(file);
	if (!buf_was_read && !result)
		return (ft_free(file));
	return (result);
}

// int	main(void)
// { 
// 	int	fd;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	return 0;
// }