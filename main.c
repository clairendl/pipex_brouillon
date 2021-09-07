/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:59:16 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/02 15:54:49 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
int main(int argc, char **argv, char *env[])
{
	char	buf[4097];
	int		fd;
	int		fd2;
	ssize_t	file;
	int		check_path_argv2;
	int		check_path_argv3;
	int		droit_acces;
	int		file2;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT);
	droit_acces = access(argv[1], R_OK);
	file = read(fd, buf, 4096);
	file2 = read(fd2, buf, 4096);
	check_path_argv2 = execve(argv[2], &argv[1], env);
	printf("%d\n", check_path_argv2);
	check_path_argv3 = execve(argv[3], &argv[4], env);
	if (argc != 5)
		return (printf("mauvais nb argv"));
/*	int n = 0;
	while (n != 5)
	{
		if (argv[n][0] == '|')
			return (printf("error pipe"));
		n++;
	}
*/
	if (fd == -1) //test fd
		return (printf("mauvais fd"));
		
	if (droit_acces == -1 ) // test access
		return (printf("mauvais access"));
	
	if (file == -1)
  	 	return (printf("mauvais read"));
	   
	 if (check_path_argv2 == -1 && check_path_argv3 == -1)
	 	return (printf("error path"));

	 if (fd2 == -1)
		return (printf("mauvais fd 2 "));
		 
		//   perror("execve");
		//   execve() ne retourne qu’en cas d’erreur */
        //   exit(EXIT_FAILURE)
		//	 close	
    /*fork(); // returns an ID (int)

	 */
	 return (0);
}


