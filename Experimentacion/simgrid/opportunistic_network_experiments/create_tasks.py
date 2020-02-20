import sys
import random

amount_of_tasks = ""
tasks_lower_range = ""
tasks_upper_range = ""

tasks = []

# try:
amount_of_tasks = int(sys.argv[1])
tasks_lower_range = int(sys.argv[2])
tasks_upper_range = int(sys.argv[3])

tasks = [random.randint(tasks_lower_range, tasks_upper_range) for iter in range(amount_of_tasks)]

# except:
	# print("Usage: python create_tasks.py <amount_of_tasks> <tasks_lower_range> <tasks_upper_range>")

file = open("tasks.txt","w")

file.write(" ".join(list(map(str, tasks))))