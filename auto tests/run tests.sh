#!/bin/bash

# Open the first terminal in ./tester1 and run the first command
gnome-terminal --geometry=80x24+800+1400 -- bash -c "cd ./tester1 && rm -f errors_log && clear; ./start.sh ../../ 0; exec bash"

# Open the second terminal in ./tester2 and run the second command
gnome-terminal --geometry=80x24+1900+1400 -- bash -c "cd ./tester2 && clear; ./test.sh ../../philo/philo; exec bash"
