from collections import deque, defaultdict
import threading
from threading import Thread
import time
from time import sleep
import random

def my_xrange(i, job_id):
	cur = 0
	while cur < i: 
		yield cur
		cur+=1

class Job(object):
	def __init__(self, job_func, kwargs, job_priority, job_id = None):
		self.job = job_func(**kwargs)
		self.priority = job_priority
		self.id = job_id if job_id else random.randint(1, 1000)
		self.num_times_run = 0
		self.time_taken = 0
		self.done = False

	def get_job_statistics(self):
		return (self.num_times_run, self.time_taken/self.num_times_run if self.num_times_run != 0 else 0)
	def run(self):
		print('running job with id {} and priority {}'.format(self.id, self.priority))
		now = time.time()
		try:
			next(self.job)
		except StopIteration:
			self.done = True
		self.time_taken += time.time() - now
		self.num_times_run+=1


class Scheduler(object):
	def __init__(self, tasks):
		self.waiting_tasks = deque(tasks)
		self.finished_tasks = []
		self.id_to_stats = {}

	def run_scheduled_jobs(self):
		# while there are jobs to process
		while len(self.waiting_tasks) > 0:
			# pick a job from the top
			current_task = self.waiting_tasks.popleft()
			# run the task until it yields
			sleep(1)
			assert not current_task.done # because whenever a task is done, we never add it back to the queue of waiting tasks
			current_task.run() # this should run until it gives up the CPU, at which point control will be transferred back into this thread
			if not current_task.done:
				self.waiting_tasks.append(current_task)
			else:
				self.finished_tasks.append(current_task)
				print('job with id {} just finished'.format(current_task.id))
		# save all of the statistics
		self.id_to_stats = {job_id: stats for job_id, stats in [(job.id, job.get_job_statistics()) for job in self.finished_tasks]}

	def add_jobs(self, num_jobs):
		print('adding {} jobs'.format(num_jobs))
		priorites = [1, 2, 3, 4]
		new_jobs = [Job(my_xrange, {'i': 2, 'job_id': 6 + i},
			job_priority=priorites[random.randint(0, len(priorites)-1)]) for i in range(num_jobs)]
		for job in new_jobs:
			print('adding a job with id {} and priority {}'.format(job.id, job.priority))
			self.waiting_tasks.append(job)
			sleep(1)

	def print_job_stats(self):
		print('\n'.join(["job with id {} ran {} times and took {} per run".format(id, tup[0], tup[1]) 
			for id, tup in self.id_to_stats.items()]))

if __name__ == '__main__':
	generator = my_xrange(1, 1)
	try:
		while True:
			print(next(generator))
	except StopIteration:
		print("done")
	priorites = [1, 2, 3, 4]
	tasks = [Job(my_xrange, {'i': 2, 'job_id': i},
		job_priority=priorites[random.randint(0, len(priorites)-1)]) for i in range(5)]
	scheduler = Scheduler(tasks)
	task_runner = Thread(target = scheduler.run_scheduled_jobs, name = 'task-runner')
	job_adder = Thread(target = scheduler.add_jobs, name = 'job-adder', kwargs ={'num_jobs': 10})
	threads = [task_runner, job_adder]
	for thread in threads:
		thread.start()
	for thread in threads:
		thread.join()
	scheduler.print_job_stats()
