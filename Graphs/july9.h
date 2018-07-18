/*
 *  1. A DAG is a directed acyclic graph. It is a graph whose edges are directional,
 *  and the graph contains no cycles, where a vertex appears more than once.
 *
 *  2. The maximum number of edges in an undirected graph will always be 1 less than
 *  the number of vertices. Asympotically speaking, this is a linear relationship.
*/
#include <cstdio>

template<typename V, typename E>
class Graph
{
public:
	using VertexID = size_t;

	VertexID addVertex(V);
	Graph& addEdge(VertexID, VertexID, E);

	class AdjMatrix
    {
    public:

        AdjMatrix(size_t x)
            : n(x), matrix(new bool[n][n])
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = false;
                }
            }
        }
    private:

        size_t n;
        bool** matrix;
    };

private:
    size_t numEdges;
    size_t numVertices;
};
