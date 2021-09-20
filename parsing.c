/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <cnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:09:37 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/20 14:51:02 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_parsing_path(char *cmd, char **envp)
{
    char	*ret;
	char	**split;
	char	**env;
	char	*thisEnv;
	char	*start = cmd;
	char	str[6] = "PATH=";
    char	**bidule;
	int		m;
	char	*join;
	int		n;
	int		check_path_argv2;
	int		check_path_argv3;
    
	n = 0;
	m = 0;
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
	while (bidule[m])
	{
		join = ft_strjoin(bidule[m], cmd);
		if (access(join, F_OK ) == 0)
			break;
		m++;
	}	
	execve(join, &cmd, NULL);
	while (bidule[n] != 0)
	{
		if (access(bidule[n], F_OK) != 0)
			n++;
		else
		{
  			check_path_argv2 = execve(join, &cmd, NULL);
			break;
		}
	}
	exit(EXIT_FAILURE);
	return (0);
	//	check_path_argv3 = execve(argv[3], &argv[4], env);		 
		//   perror("execve");
		//   execve() ne retourne qu’en cas d’erreur 
        //   exit(EXIT_FAILURE)
		//	 close	
   // fork(); // returns an ID (int)
}

char *good_path(char **argv)
{
	if (argv[2][0] == '/' && access(argv[1], F_OK) == 0)
		return (argv[2]);
	if (argv[3][0] == '/' && access(argv[4], W_OK) == 0)
		return (argv[3]);
    else
        return (NULL);
}