/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhmart <mikhmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:43:41 by mikhmart          #+#    #+#             */
/*   Updated: 2024/04/03 20:09:38 by mikhmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *ch = NULL;
	int	i;
	char lt;

		if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if(ch == NULL)
	// {
	// 	ch = (char *)malloc(BUFFER_SIZE * sizeof(char));
	// 	read(fd, ch, BUFFER_SIZE);
	// }
	i = 0;
	ch = malloc(BUFFER_SIZE + 1);
	while (read(fd, &lt, 1))
	{
		ch[i] = lt;
		++i;
		if(lt == '\n')
			break;
	}
	ch[i] = '\0';
	// while 
	return (ch);
}

int	main(void)
{ 
	int	fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return 0;
}