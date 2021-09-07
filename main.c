/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:59:16 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/07 16:16:31 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <libc.h>

int main(int argc, char **argv, char **envp)
{

	char str[6] = "PATH=";
	char *ret;
	char *start;
	char **split;
	int n;
	char **env;
	char *thisEnv;

	n = 0;
	env = envp;

	char	buf[4097];
	int		fd;
	int		fd2;
	ssize_t	file;
	int		check_path_argv2;
	int		check_path_argv3;
	int		droit_acces;
	int		file2;
	char 	**bidule;
	int		m;
	char	*join;
	
	fd = open(argv[1], O_RDONLY);
	droit_acces = access(argv[1], R_OK);
	file = read(fd, buf, 4096);

	/*
	if (argv[2][0] == '/' && access(argv[2], F_OK) == 0)
		return (cmd)
		//	execve(join, &argv[2], NULL);
		executer avec exceve*/

	start = argv[2];
	printf("start : %s\n", start);
	split = ft_split(start, ' ');
	printf("split[0] = %s\n", split[0]);
	printf("split[1] = %s\n", split[1]);

	while(*env)
    {
    	thisEnv = *env;
		ret = ft_strchr(thisEnv, str);
    	if (ft_strchr(thisEnv, str) != NULL)
			bidule = ft_split(ret, ':');
		env++;
	}
	m = 0;
	while (bidule[m])
	{
		join = ft_strjoin(bidule[m], argv[2]);
	//	printf("%s\n", join);
		if (access(join, F_OK ) == 0)
		{
			//return (join);
		//	printf("join : %s\n", join);
			break;
		}
		m++;
	}	

	execve("/bin/ls", &argv[2], &argv[1]);
//	fd2 = open(argv[4], O_CREAT);
//	file2 = read(fd2, buf, 4096);
//		printf("bidule[%d] = %s\n", m, join);
//		printf("bidule[%d] = %s\n", m, join);
	//	join = ft_strjoin(bidule[m], argv[2]);
	//	printf("join  = %s\n", join);
		//printf("exe : %d\n", execve(join, &argv[2], NULL)); 


//	printf("path : %d\n", check_path_argv2);
	
	/*while (bidule[n] != 0)
	{
		if (access(bidule[n], F_OK) != 0 )
		{
			printf("KIT KAT\n");
			n++;
		}
		else
		{
  			check_path_argv2 = execve(join, &argv[2], NULL);
			printf("path : %d\n", check_path_argv2);
			printf("join2 : %s\n", join);
			printf("path : %d\n", check_path_argv2);
			break;
			
		}
	}*/


/*	
	//	check_path_argv3 = execve(argv[3], &argv[4], env);
	if (argc != 3)
		return (printf("mauvais nb argv"));
	n = 0;
	while (n != 5)
	{
		if (argv[n][0] == '|')
			return (printf("error pipe"));
		n++;
	}

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
		//   execve() ne retourne qu’en cas d’erreur 
        //   exit(EXIT_FAILURE)
		//	 close	
   // fork(); // returns an ID (int)

*/	 
	 return (0);
}
