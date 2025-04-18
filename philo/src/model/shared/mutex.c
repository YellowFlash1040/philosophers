#include "mutex.h"

t_mutex	*init_mutex(void)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));

	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (free(mutex), NULL);
	return (mutex);
}

void	destroy_mutex(t_mutex **mutex_ref)
{
	t_mutex	*mutex;

	if (!mutex_ref || !*mutex_ref)
		return ;
	mutex = *mutex_ref;
	pthread_mutex_destroy(mutex);
	free(mutex);
	*mutex_ref = NULL;
}
