/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:52:53 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 18:36:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include "environment.h"
# include "philosopher.h"

# define THREAD_DATA_INIT_ERR 60

typedef struct thread
{
	t_philosopher	*philosopher;
	t_environment	*environment;
}					t_thread;

t_thread			*init_thread_data(void);
void				destroy_thread_data(t_thread **thread);

#endif