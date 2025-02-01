/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soul.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:07:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/30 16:44:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUL_H
# define SOUL_H

# include <pthread.h>
# include <stdlib.h>

typedef pthread_t	t_soul;

t_soul				*init_soul(void);
void				destroy_soul(t_soul **soul);

#endif