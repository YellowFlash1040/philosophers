/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_setup.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:31:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/04/18 16:53:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_SETUP_H
# define ENVIRONMENT_SETUP_H

# include "environment.h"
# include "timings_setup.h"
# include "mutex.h"

int	setup_environment(t_environment **environment, t_params *params);

#endif