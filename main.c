/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:59:16 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/15 16:09:22 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <libc.h>

int main(int argc, char **argv, char **envp)
{
	char	buf[4097];
	int		fd[2];
	ssize_t	file;
	int		check_path_argv2;
	int		check_path_argv3;
	int		droit_acces;
	char *join;
	int		file_dup;
	
	fd[0] = open(argv[1], O_RDONLY);
	droit_acces = access(argv[1], R_OK);
	file = read(fd[0], buf, 4096);
	pipe(fd);
	int	id;
	id = fork();
	if (ft_verif_input(argc, argv) == -1
		|| ft_verif_files(fd[2], check_path_argv2, check_path_argv3) == -1
		|| ft_read_and_access(droit_acces, file) == -1 
		|| ft_pipe_and_fork(fd, id) == -1)
//		|| ft_check_file(fd, argv, buf);
			return (-1);
	if (id != 0) // PARENT
	{
		if (wait(fd[0]) == -1)
		{
			perror("No children to wait for");
			return (-1);
		}
	}
 	else // CHILD
    {
		int file_dup = dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if (good_path(argv) != NULL)
			execve(argv[1], &argv[2], NULL);
		else
			ft_parsing_path(argv[2], envp);
		close(fd[1]);
    }
    // parent process
	int file_dup = dup2(fd[0], STDOUT_FILENO);
	close(fd[1]);
	if (good_path(argv) != NULL)
		execve(argv[4], &argv[3], NULL);
	else
		ft_parsing_path(argv[3], envp);
    close(fd[0]);
	return (0);
	}