# Alternative solution to Parenting Partner Returns
# Passed all tests
def solve(schedule, N):
    orderedSchedule = schedule.copy()
    orderedSchedule.sort()
    assigned = {} # use identifier as key (ranges from 0 ... N-1)
    cLast = 0
    jLast = 0
    for task in orderedSchedule:
        if cLast == 0:
            assigned[task[2]] = "C"
            cLast = task[1]
        elif jLast == 0 :
            assigned[task[2]] = "J"
            jLast = task[1]
        elif cLast <= task[0]:
            assigned[task[2]] = "C"
            cLast = task[1]
        elif jLast <= task[0]:
            assigned[task[2]] = "J"
            jLast = task[1]
        else:
            return "IMPOSSIBLE"
    
    final = ""
    for p in schedule:
        final += assigned[p[2]]
    
    return final

T = int(input())
for k in range(1,T+1):
    N = int(input())
    schedule = []
    for identifier in range(N):
        times = list(map(int,input().split())) # 360 420 -> [360,420]
        times.append(identifier) # [360, 420, identifier]
        schedule.append(tuple(times)) # [360, 420, identifier] -> (360, 420, Identifier)
    result = solve(schedule, N)
    print("Case #{}: {}".format(k, result))
