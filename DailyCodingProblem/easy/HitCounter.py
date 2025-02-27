import bisect
from math import floor

class HitCounter:
    def __init__(self):
        self.total_hits = 0
        self.timestamps = {}

    def record(self, timestamp):
        if timestamp not in self.timestamps:
            self.timestamps[timestamp] = 1
            self.total_hits += 1
        else:
            self.timestamps[timestamp] += 1
            self.total_hits += 1

        for k, v in self.timestamps.items():
            if timestamp < k:
                self.timestamps[k] += 1
    
    def total(self):
        return self.total_hits

    
    def range(self, lower, upper):
        return self.timestamps[upper] - self.timestamps[lower]

class HitCounterSol:
    def __init__(self):
        self.hits = []
        self.counter = 0

    def record(self, timestamp):
        self.counter += 1
        
        minute = floor(timestamp / 60)
        i = bisect.bisect_left([hit[0] for hit in self.hits], minute)
        if i < len(self.hits) and self.hits[i][0] == minute:
            self.hits[i] = (minute, self.hits[i][1] + 1)
        else:
            self.hits.insert(i, (minute, 1))

    def total(self):
        return self.counter

    def range(self, lower, upper):
        lower_minute = floor(lower / 60)
        upper_minute = floor(upper / 60)
        lower_i = bisect.bisect_left([hit[0] for hit in self.hits], lower_minute)
        upper_i = bisect.bisect_right([hit[0] for hit in self.hits], upper_minute)
        
        return sum(self.hits[i][1] for i in range(lower_i, upper_i))

def main():

    # Test 1: Should return 4

    hc = HitCounterSol()
    hc.record(1)
    hc.record(62)
    hc.record(1)
    hc.record(1)
    hc.record(123)
    print(hc.total())
    print(hc.range(1, 62))
    print(hc.hits)

main()
