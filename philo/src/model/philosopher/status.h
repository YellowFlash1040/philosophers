/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:33 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum e_status
{
	THINKING,
	HAS_TAKEN_FORK,
	EATING,
	SLEEPING,
	DIED
}		t_status;

char	*get_status_message(t_status status);

#endif