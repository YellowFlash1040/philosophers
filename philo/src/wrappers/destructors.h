/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:16:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/31 14:30:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCTORS_H
# define DESTRUCTORS_H

# include "circular_list.h"
# include "fork.h"
# include "thread.h"

void	clear_philosopher(void *philosopher);
void	clear_fork(void *value);
void	clear_thread(void *value);

#endif