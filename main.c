/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:59:16 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/07 10:09:08 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"
#include <libc.h>

int	is_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

size_t	count_charset(char *s, char c)
{
	int		count;
	size_t	words;

	count = 1;
	words = 0;
	while (s && *s)
	{
		if (is_charset(*s, c))
			count = 1;
		else if (count == 1)
		{
			words++;
			count = 0;
		}
		s++;
	}
	return (words);
}

size_t	count_char(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_charset(s[i], c))
		i++;
	return (i);
}

char	**ft_free(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**new;
	size_t	count;
	size_t	j;
	size_t	k;

	j = -1;
	count = count_charset(s, c);
	k = 0;
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s || !new)
		return (NULL);
	while (++j < count)
	{
		while (is_charset(*s, c))
			s++;
		new[j] = (char *)malloc(sizeof(char) * (count_char(s, c) + 1));
		if (!new[j])
			return (ft_free(new));
		k = 0;
		while (*s && !is_charset(*s, c))
			new[j][k++] = *s++;
		new[j][k] = 0;
	}
	new[j] = 0;
	return (new);
}

/*int main(int argc, char **argv, char *env[])
{
	char	buf[4097];
	int		fd;
	int		fd2;
	ssize_t	file;
	int		check_path_argv2;
	int		check_path_argv3;
	int		droit_acces;
	int		file2;
	
	*env = {"/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin", "/sbin", "/usr/local/go/bin", "/usr/local/mongodb/bin", "/usr/local/munki"};
	printf("%s", env[0]);
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
	int n = 0;
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
    fork(); // returns an ID (int)

	 
	 return (0);
}
*/
int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char *str)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == str[j])
		{	//return ((char *)s);
			i++;
			j++;
			if (str[j] == 0)
				return ((char *)s + i);
		}
		i++;
	}
	if (!*s && !*str)
		return (NULL);
	return (NULL);
}


int main(int ac, char **av, char **envp)
{
	char str[6] = "PATH=";
	char *ret;
	char **split;
	int n;
	char **env;
	char *thisEnv;

	n = 0;
	env = envp;
	while(*env)
    {
    	thisEnv = *env;
		ret = ft_strchr(thisEnv, str);
    	if (ft_strchr(thisEnv, str) != NULL)
		{
			printf("%s\n", ret);
			split = ft_split(ret, ':');
			while (split[n] != '\0')
			{
				printf("splitou[%d] =  %s\n", n, split[n]);
				n++;
			}
		}
		env++;
	} 
	return (0);
}









