#ifndef PRINTER_H
# define PRINTER_H

# include "status.h"
# include "thread.h"
# include <pthread.h>

void	print_status(t_thread *thread, t_status status, t_time_point *now_ref);

#endif
