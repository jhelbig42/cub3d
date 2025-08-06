/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_custom.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:04:43 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/06 15:04:45 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_CUSTOM_H
# define GET_NEXT_LINE_CUSTOM_H

# include <stdio.h>
# include <stdbool.h> // bools
# include <stdlib.h> //malloc
# include <unistd.h> // open, read
# include <fcntl.h> // flags for open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_storebuffer
{
	char					*content;
	struct s_storebuffer	*next;
}	t_storebuffer;

char			*get_next_line(int fd, bool done);
char			*create_next_line(t_storebuffer **new_line_list);
bool			find_newline(t_storebuffer **new_line_list);
void			read_buffers(t_storebuffer **new_line_list, int fd);
void			prepare_storebuffer_next_round(t_storebuffer **new_line_list);

//utils
size_t			line_size(t_storebuffer **new_line_list);
void			storebuffer_clear(t_storebuffer **lst);
t_storebuffer	*find_last_node(t_storebuffer **new_line);
void			storebuffer_new_node_add_back(t_storebuffer **lst,
					char *content);
//void	*ft_calloc(size_t nmemb, size_t size);

#endif
