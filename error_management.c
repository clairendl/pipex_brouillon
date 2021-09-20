/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:09 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/20 15:32:55 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_verif_input(int argc, char **argv)
{
	int n;
	n = 0;
	if (argc != 5)
	{
		perror("Incorrect number of arguments in command line");
		return (-1); // exit(EXIT_FAILURE);
	}
	while (n != 5)
	{
		if (argv[n][0] == '|')
		{
			perror("error pipe");
			return (-1); // exit(EXIT_FAILURE);
		}
		n++;
	}
	return (0);
}

int	ft_verif_files(int fd[2], int check_path_argv2, int check_path_argv3)
{
	if (fd[0] == -1 || fd[1] == -1) //test fd avant : fd et fd2
	{
		perror("fd error");
		return (-1); // exit(EXIT_FAILURE);
	}  
	if (check_path_argv2 == -1 && check_path_argv3 == -1)
	{
	 	perror("Error path");
		return (-1); // exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_read_and_access(int droit_acces, ssize_t file)
{
	if (droit_acces == -1 )
	{
		perror("Access error");
		return (-1); // exit(EXIT_FAILURE);
		// ou tout remplacer par
		// 	exit(ft_put_error("error during pipe: ", strerror(errno), "", 1));
	}
	
	if (file == -1)
	{
  	 	perror("Read error");
		return (-1); // exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_pipe_and_fork(int fd[2], int id)
{
	if (pipe(fd) == -1)
	{
		perror("Error with pipe function");
		return (-1); // exit(EXIT_FAILURE);
	}
	if (id == -1)
	{
		perror("Error with child procesor creation");
		return (-1); // exit(EXIT_FAILURE);
	}
	return (0);
}

/*int ft_check_file(int *fd, char **argv, int buf)
{
	char
	if (fd[2] = open(argv[4], O_CREAT) == -1)
		return (-1);
	if (file2 = read(fd[2], buf, 4096) 
	join = ft_strjoin(bidule[m], argv[2]);
    return(0);
}*/