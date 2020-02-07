/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:16:36 by jko               #+#    #+#             */
/*   Updated: 2020/02/05 15:13:09 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define NO_ARG_MSG "File name missing.\n"
#define NO_ARG_MSG_SIZE 20

#define TOO_MANY_ARG_MSG "Too many arguments.\n"
#define TOO_MANY_ARG_MSG_SIZE 21

#define CANNOT_READ_MSG "Cannot read file.\n"
#define CANNOT_READ_MSG_SIZE 19

int	main(int argc, char **argv)
{
	char	buf[100];
	int		fd;
	int		n;

	if (argc == 1)
	{
		write(2, NO_ARG_MSG, NO_ARG_MSG_SIZE);
		return (0);
	}
	else if (argc > 2)
	{
		write(2, TOO_MANY_ARG_MSG, TOO_MANY_ARG_MSG_SIZE);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, CANNOT_READ_MSG, CANNOT_READ_MSG_SIZE);
		return (0);
	}
	while ((n = read(fd, buf, 100)))
		write(1, buf, n);
	close(fd);
	return (0);
}
