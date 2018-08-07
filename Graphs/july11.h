#include <limits>
#include <cstddef>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

#define dist first
#define done second

static double infinity = std::numeric_limits<double>::infinity();

// void parseRoadDistance() {
//     std::vector<double> adjList;
//     std::string input;
//     std::string town;
//     double distance;
//     std::ifstream roadDistances("road-distances.csv");
//
//     while (roadDistances.good()) {
//         getline(roadDistances, input, ',');
//     }
//
// }

class RoadGraph {
public:
    using VertexID = size_t;

    RoadGraph()
        : numVertices(0)
    {
    }

    ~RoadGraph() {
        std::cout << "are you the culprit" << '\n';
        // for (auto v : this->vertices) {
        //     delete v;
        // }
    }

    VertexID addVertex(std::string name) {
        // construct a new node and place its pointer in the vertices vector
        Node* v = new Node(name, this->numVertices);
        this->vertices.emplace_back(std::move(v));

        this->adjList[numVertices].push_back({});


        std::cout << "Adding vertex for " << vertices[numVertices]->name << '\n';


        // increment for next vertex addition and for correct counting
        this->numVertices++;

        return this->numVertices - 1;
    }

    RoadGraph& addEdge(VertexID n1, VertexID n2, double dist) {
        std::cout << "attempting to add road of distance " << dist << " between " << vertices[n1]->name << " and " << vertices[n2]->name<< '\n';

        this->adjList[n1].resize(numVertices);
        this->adjList[n2].resize(numVertices);
        // edit adjacency list for vertices
        this->adjList[n1][n2] = dist;
        this->adjList[n2][n1] = dist;

        std::cout << this->adjList[n1][n2] << '\n';
        std::cout << this->adjList[n2][n1] << '\n';

        return *this;

    }

    void calcShortestPaths() {

        size_t n = vertices.size();

        for (size_t i = 0; i < n; i++) {
            this->adjList[i][i] = 0;
            this->shortestPaths[i].resize(n, infinity);
        }

        // initialize shortestPaths map to be same as adjacency list
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (adjList[i][j] != 0 or i == j) {
                    shortestPaths[i][j] = adjList[i][j];
                }
            }
        }

        for (size_t k = 0; k < n; k++) {
            for (size_t i = 0; i < n; i++) {
                for(size_t j = 0; j < n; j++) {
                    if (shortestPaths[i][k] + shortestPaths[k][j] < shortestPaths[i][j]) {
                        // make the update to the shortest path
                        shortestPaths[i][j] = shortestPaths[i][k] + shortestPaths[k][j];
                    }
                }
            }
        }




    }

    struct Node {
        Node(std::string n, VertexID num)
            : name(n), id(num)
        {
        }

        std::string name;
        VertexID id;
    };

    std::map<VertexID, std::vector<double>> shortestPaths;

private:
    size_t numVertices;
    std::vector<Node*> vertices;
    std::map<VertexID, std::vector<double>> adjList;
};
