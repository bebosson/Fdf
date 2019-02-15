/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:17:19 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/14 01:08:45 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);
#endif
