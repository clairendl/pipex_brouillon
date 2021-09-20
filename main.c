/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:59:16 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/20 16:31:51 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <libc.h>

int main(int argc, char **argv, char **envp)
{
	char	buf[4097];
	int		fd[2];
	//ssize_t	file;
	//ssize_t	file_2;
	int		check_path_argv2;
	int		check_path_argv3;
	//int		droit_acces;
	//int		droit_acces_2;
	char 	*join;
	int		file_dup;
	int		status;
	int		id_child_1;
	int		id_child_2;
	
	fd[0] = open(argv[1], O_RDONLY);
	// verif valeur renvoie fd
	////droit_acces = access(argv[1], R_OK); pas besoin, si le fd < 0 au dessus, renvoie error
	////file = read(fd[0], buf, 4096); pas besoin, si le fd < 0 au dessus, renvoie error
	// ouverture deuxieme fd : faux non ?
	fd[1] = open(argv[4], O_CREAT | O_RDWR, 0644);
	////droit_acces_2 = access(argv[4], R_OK ); pas besoin, si le fd < 0 au dessus, renvoie error
	////file_2 = read(fd[1], buf, 4096); pas besoin, si le fd < 0 au dessus, renvoie error
	//
	pipe(fd);
	id_child_1 = fork(); 			// CREATION ENFANT 1
	//    if (child1 < 0)
    //  return (perror("Fork: "));	
	if (id_child_1 == 0)
        child_one(&fd[0], argv, envp);
	if (id_child_1 != 0)
		id_child_2 = fork(); 		// CREATION ENFANT 2
	 //   if (child2 < 0)
      //   return (perror("Fork: "));
	if (id_child_2 == 0)
        child_two(&fd[1], argv, envp);
	// GESTION ERROR :
	if (ft_verif_input(argc, argv) == -1
		|| ft_verif_files(&fd[2], check_path_argv2, check_path_argv3) == -1
	// a virer ?	|| ft_read_and_access(droit_acces, file) == -1 
		|| ft_pipe_and_fork(fd, id_child_2) == -1
		|| ft_pipe_and_fork(fd, id_child_1) == -1)
//		|| ft_check_file(fd, argv, buf);
			return (-1);
    close(fd[0]);         // this is the parent
    close(fd[1]);         // doing nothing
    waitpid(id_child_1, &status, 0);  // supervising the children
    waitpid(id_child_2, &status, 0);  // while they finish their tasks
	return (0);
}





/*	if (id != 0) // PARENT
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
    / parent process
	file_dup = dup2(fd[0], STDOUT_FILENO);
	close(fd[1]);
	if (good_path(argv) != NULL)
		execve(argv[4], &argv[3], NULL);
	else
		ft_parsing_path(argv[3], envp);
    close(fd[0]);
	return (0);
	}*/