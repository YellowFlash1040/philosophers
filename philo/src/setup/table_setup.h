/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_setup.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:33:06 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/01 16:42:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_SETUP_H
# define TABLE_SETUP_H

# include "table.h"

# define FORKS_INIT_ERR 21

int	setup_table(t_table **table, int forks_amount);

#endif