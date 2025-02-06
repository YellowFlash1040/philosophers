/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:34:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 17:50:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_atoi.h"
# include "global_status_codes.h"
# include "params.h"

# define PHILOSOPHERS_COUNT_ERR 130
# define TIME_TO_DIE_ERR 131
# define TIME_TO_EAT_ERR 132
# define TIME_TO_SLEEP_ERR 133
# define OPTIONAL_PARAM_ERR 134

int	parse_params(int argsc, char **args, t_params **params_ref);

#endif