function press_enter {
	xdotool key Return && sleep 1s
	
	sleep 1s
}

function run_command {
	xdotool type "$1"  && sleep 1s
	press_enter

	sleep 1s
}

function go_right {
	xdotool key ctrl+Page_Down
	
	sleep 1s
}

function go_left {
	xdotool key ctrl+Page_Up
	
	sleep 1s
}

function clean_up_logs {
	xdotool type "ssh -t fosco@saclay.iot-lab.info 'ssh -t root@node-a8-1.saclay.iot-lab.info rm workers_logs.txt'" & sleep 1s
	press_enter
	sleep 5s

	xdotool type "ssh -t fosco@saclay.iot-lab.info rm workers_logs.txt" & sleep 1s
	press_enter
	sleep 5s

	xdotool type "rm workers_logs.txt" && sleep 1s
	press_enter
	sleep 5s

	sleep 1s
}

function fetch_result {
	xdotool type "ssh fosco@saclay.iot-lab.info \"rsync -avzhe ssh root@node-a8-1.saclay.iot-lab.info:/home/root/workers_logs.txt workers_logs.txt\"" && sleep 1s
	press_enter
	sleep 15s

	xdotool type "rsync -avzhe ssh fosco@saclay.iot-lab.info:/senslab/users/fosco/workers_logs.txt workers_logs.txt" && sleep 1s
	press_enter
	sleep 5s

	sleep 1s
}

function move_results_together {
	xdotool type "cat workers_logs.txt >> experiments_results.txt" && sleep 1s
	press_enter

	end="________________________________________________________________________________________________________________"
	xdotool type "echo \"${end}\n\n\n\n\n\" >> experiments_results.txt" && sleep 1s
	press_enter
	sleep 2s

	clean_up_logs

	sleep 1s
}

function new_window {
	gnome-terminal
	sleep 1s
	# xdotool key ctrl+shift+n
}

function close_window {
	xdotool key alt+F4
	sleep 1s
}

function run_experiment {
	for i in $(seq 1 $1)
	do
		new_window
		sleep 5s

		run_command "./compileAndSend.sh normal"
		sleep 240s

		go_right

		press_enter
		sleep 30s

		go_left
		fetch_result
		sleep 15s

		move_results_together

		if [[ ${2} != "" ]]
		then
			sleep ${2}
		else
			sleep 10s
		fi

		close_window
	done
}

# function kill_process {
# 	kill -9 $1
# }

# function listen_for_esc_to_kill_process {
# 	if [[ $key = q ]]
# 	then
# 		kill_process $1
# 		break
# 	fi
# }

# listen_for_esc_to_kill_process $$ &

run_experiment $1 $2