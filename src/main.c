#include "simulation.h"

void	free_data(t_simulation_data **data);

int	main(int argsc, char **args)
{
	int					philosophers_amount;
	t_simulation_data	*data;

	(void)argsc;
	(void)args;
	philosophers_amount = 8;
	data = init_data();
	if (!data)
		return (1);
	data->timings->time_to_eat = 2000 * 1000;
	data->timings->time_to_sleep = 2000 * 1000;
	if (!create_philosophers(&data->philosophers, philosophers_amount))
		return (PHILOSOPHERS_INIT_ERR);
	data->table = init_table();
	if (!data->table)
		return (free_data(&data), TABLE_INIT_ERR);
	if (!seat_philosophers_at_the_table(data->philosophers, data->table))
		return (free_data(&data), PHILOSOPHERS_PLACEMENT_ERROR);
	start_simulation(data);
	//
	free_data(data);
	return (0);
}

void	free_data(t_simulation_data **data)
{
	t_simulation_data	*simulation_data;

	if (!data || !*data)
		return ;
	simulation_data = *data;
	if (simulation_data->table)
		destroy_table(&simulation_data->table);
	if (simulation_data->philosophers)
		destroy_table(&simulation_data->philosophers);
	free(simulation_data);
	*data = NULL;
}
