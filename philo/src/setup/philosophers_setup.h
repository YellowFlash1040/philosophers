/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_setup.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:26:24 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:46:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_SETUP_H
# define PHILOSOPHERS_SETUP_H

# include "circular_list.h"
# include "destructors.h"
# include "philo_actions.h"
# include "philosopher.h"

# define PHILOSOPHER_ACTION philo_live

# define PHILOSOPHERS_INIT_ERR 22

int	setup_philosophers(t_circular_list **philosophers, int amount);

#endif