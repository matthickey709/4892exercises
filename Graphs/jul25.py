# To ensure that the algorithim runs in Theta(V+E) time, it is necessary that data
# structures are chosen such that iterating through all vertices to make sure all
# degrees are even is done in linear time, and to find the circuit (if possible)
# a data structure must be chosen such that all neighbours in the graph will be
# iterated over in linear time.

def find_euler(v):
    euler_exists = True

    # check that all vertices in the graph have an even degree
    for v in vertices:
        if v.degree is even:
            continue
        else:
            euler_exists = False
            break

    if possible:
        count = 0
        circuit_order = [v.id]  # initalize path with starting vertex
        # start dfs from passed in vertex
        circuit_order = depth_first_search(v, v, circuit_order, count)

        while circuit_order not all vertices:
            backup = circuit_order[x] # where x is the first vertex with unexplored neighbours
            circuit_order = circuit_order[0:x]  # modify order

            circuit_order = depth_first_search(orig, backup, circuit_order, count)

        return circuit_order
    # if an odd vertex, no circuit found
    return False




def depth_first_search(orig, v, c_o, cnt):
    v.visited = True
    for n in v.neighbours:
        if orig is in n.neighbours and count > 0:
            c_o.append(orig.id)
            return c_o
        if n.visited is False:
            c_o.append(n)
            depth_first_search(n)
