/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:47:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 16:49:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

# define MUTEX_INIT_ERR 39

typedef pthread_mutex_t	t_mutex;

t_mutex	*init_mutex(void);
void	destroy_mutex(t_mutex **mutex_ref);

#endif
