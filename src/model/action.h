/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:54:07 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/28 18:44:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include <pthread.h>

typedef enum
{
	THINK,
	EAT,
	SLEEP
}				e_action_type;

typedef void	*(*t_action)(void *);

#endif