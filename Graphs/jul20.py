"""write an algorithim for visiting graph vertices according to topological order
    (topological sort). Show run time complexity is Theta(V + E)"""
def topologicalSort():
    for v in vertices: # this is theta(|v|)
        if v.in_degree == 0:
            worklist.add(v)

    for v in worklist: # this is theta(|e|), is it is dependent on neighbours
        for n in v.neighbours:
            if n.in_degree < 0:
                n.in_degree--
                if n.in_degree == 0:
                        worklist.add(n)



"""write an algorithim for calculating schedule slack"""

def slackCalc():
    for v in vertices:
        v.slack = 0
        for n in v.neighbours:
            if v.distance - n.distance < 0:
                v.slack = v.distance - n.distance
