#include <cstddef>  // size_t
#include <limits>   // infinity
#include <map>      // std::map
#include <vector>   // std::vector

// template <typename T>
void shortestPaths(size_t** adj, size_t** shortest, size_t n) {

    // define infinity in relation to the type
    int infinity = std::numeric_limits<int>::infinity();

    // set shortest paths to infinity if not adjacent, to 0 if i,i, or edge width for adjacent
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (adj[i][j] != 0 or i == j) {
                shortest[i][j] = adj[i][j];
            } else {
                shortest[i][j] = infinity;
            }
        }
    }

    for (size_t k = 0; k < n; k++) {
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                // check if there is a shorter path than currently recorded
                if (shortest[i][k] + shortest[k][j] < shortest[i][j]) {
                    shortest[i][j] = shortest[i][k] + shortest[k][j];
                }
            }
        }
    }


}
