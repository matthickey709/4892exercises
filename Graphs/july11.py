# doing this in python (pseudocode) for now, will redo in c++ when midterms end


def parse_csv(self):
    open('road-distances.csv') as roadfile
    comma delimit the first line, save each token as a city in a list
    line by line save the distances in a dictionary


# july13 exercise

def road_distance(point_a, point_b):
    start at point_a
    find distance to each of point_a neighbours
    return distance when point_b found
    find distance to each neighbour from point_a neighbours
    recurse until point_b found
