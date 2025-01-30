/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:11:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 17:49:10 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include "circular_list.h"
# include "philosopher_pair.h"
# include <stdlib.h>

# define TABLE_INIT_ERR 10
# define PHILOSOPHERS_PLACEMENT_ERROR 11

typedef struct table
{
	t_circular_list	*pairs;
}					t_table;

t_table				*init_table(void);
void				destroy_table(t_table **table);
bool				seat_philosophers_at_the_table(t_circular_list *philosophers,
						t_table *table);

#endif