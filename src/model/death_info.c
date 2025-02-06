#include "death_info.h"

t_death_info	*init_death_info(void)
{
	t_death_info	*death_info;

	death_info = (t_death_info *)malloc(sizeof(t_death_info));
	if (!death_info)
		return (NULL);
	death_info->philo_id = -1;
	death_info->timestamp = (t_time_point){0};
	return (death_info);
}

void	destroy_death_info(t_death_info **death_info)
{
	if (!death_info || !*death_info)
		return ;
	free(*death_info);
	*death_info = NULL;
}
