/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:09:37 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/15 16:22:25 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_parsing_path(char *cmd, char **envp)
{
    char *ret;
	char **split;
	char **env;
	char *thisEnv;
	char *start = cmd;
	char str[6] = "PATH=";
 
    char 	**bidule;
	int		m;
	char	*join;
    
	env = envp;
	split = ft_split(start, ' ');
	while (*env)
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
		join = ft_strjoin(bidule[m], cmd);
		if (access(join, F_OK ) == 0)
			break;
		m++;
	}	
	execve(join, &cmd, NULL);

	int n;
	int		check_path_argv2;
	int		check_path_argv3;
    n = 0;
	while (bidule[n] != 0)
	{
		if (access(bidule[n], F_OK) != 0 )
		{
			printf("KIT KAT\n");
			n++;
		}
		else
		{
  			check_path_argv2 = execve(join, &cmd, NULL);
			printf("path : %d\n", check_path_argv2);
			printf("join2 : %s\n", join);
			printf("path : %d\n", check_path_argv2);
			break;
			
		}
	}


	
	//	check_path_argv3 = execve(argv[3], &argv[4], env);

		 
		//   perror("execve");
		//   execve() ne retourne qu’en cas d’erreur 
        //   exit(EXIT_FAILURE)
		//	 close	
   // fork(); // returns an ID (int)
}

char *good_path(char **argv)
{
	if (argv[2][0] == '/' && access(argv[2], F_OK) == 0)
		return (argv[2]);
    else
        return (NULL);
}