/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:11:52 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/07 13:17:21 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

# define FORK_INIT_ERR 30

typedef enum e_fork_name
{
	LEFT = 0,
	RIGHT = 1
}						t_fork_name;

typedef pthread_mutex_t	t_fork;

t_fork					*init_fork(void);
bool					destroy_fork(t_fork **fork);

#endif