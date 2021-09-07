/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:09 by cnicolas          #+#    #+#             */
/*   Updated: 2021/09/02 13:23:11 by cnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_access_file(int fd, char **argv, char *filename)
{
	int	result;
	
	result = access(filename, F_OK);
	if (result == -1)
		return (-1);
	else
		return (0);
}

