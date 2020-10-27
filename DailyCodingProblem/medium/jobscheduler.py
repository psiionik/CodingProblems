'''
Implement a job scheduler which takes in a funtion f and an integer n, and calls f after n milliseconds
'''

# SOLUTION 1

# Spin off a new thread on each function we want to delay, sleep the requested amount, and then run the function
# Have only one dedicated thread to run the functions and use a data structure to store the functions (list)
# Need some sort of polling to check when to run a function


import time
import threading


class Scheduler:
    def __init__(self):
        self.fns = [] # tuple of (function, time)
        t = threading.Thread(target=self.poll)
        t.start()
    
    def poll(self):
        while True:
            now = time.time()* 1000
            for fn, due in self.fns:
                if now > due:
                    fn()
            self.fns = [(fn, due) for (fn, due) in self.fns if due > now]
            time.sleep(0.01)

    def delay(self, f, n):
        self.fns.append((f, time.time() * 1000 + n))

def printSomething():
    print('message')

def main():
    sched = Scheduler()
    sched.delay(printSomething(), 1000)
    sched.delay(printSomething(), 10000)

main()