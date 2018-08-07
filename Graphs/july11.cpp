#include "july11.h"
using VertexID = size_t;

int main(int argc, char const *argv[]) {
    RoadGraph avalon;
    std::map<std::string, VertexID> townIndex;
    // Add the towns first
    townIndex["Bay Bulls"] = avalon.addVertex("Bay Bulls");
    townIndex["CBS"] = avalon.addVertex("CBS");
    townIndex["Goulds"] = avalon.addVertex("Goulds");
    townIndex["Holyrood"] = avalon.addVertex("Holyrood");
    townIndex["Paradise"] = avalon.addVertex("Paradise");
    townIndex["Portugal Cove"] = avalon.addVertex("Portugal Cove");
    townIndex["St. John's"] = avalon.addVertex("St. John's");


    // Now ad
    avalon.addEdge(0, 2, 15.3);  // Bay Bulls, Goulds, 15.3
    avalon.addEdge(0, 3, 31.9);  // Bay Bulls, Holyrood, 31.9
    avalon.addEdge(1, 3, 24.1);  // CBS, Holyrood, 24.1
    avalon.addEdge(1, 4, 6.6);   // CBS, Paradise, 6.6
    avalon.addEdge(1, 5, 16.4);  // CBS, Portugal Cove, 16.4
    avalon.addEdge(2, 4, 17.5);  // Goulds, Paradise, 17.5
    avalon.addEdge(2, 6, 14.3);  // Goulds, St. John's, 14.3
    avalon.addEdge(4, 5, 12.5);  // Paradise, Portugal Cove, 12.5
    avalon.addEdge(4, 6, 18.6);  // Paradise, St. John's, 18.6
    avalon.addEdge(5, 6, 14.2);  // Portugal Cove, St. John's, 14.2

    avalon.calcShortestPaths();

    for (auto i : avalon.shortestPaths) {
        for (int j = 0; j < i.second.size(); j++) {
            std::cout << "shorest path from " << i.first << " to " << j << " = " << i.second[j] << '\n';
        }
    }

    std::cout << "hhhhhhhh" << '\n';



    return 0;
}
