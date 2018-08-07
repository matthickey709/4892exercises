#include "jul23.h"



int main(int argc, char const *argv[]) {

    static size_t adj[6][6];
    static size_t short_[6][6];


    // set adj
    adj[0][1] = 5;
    adj[0][2] = 2;
    adj[1][0] = 5;
    adj[1][3] = 3;
    adj[2][0] = 2;
    adj[2][3] = 1;
    adj[2][4] = 1;
    adj[3][1] = 3;
    adj[3][2] = 1;
    adj[3][5] = 2;
    adj[4][2] = 1;
    adj[4][5] = 4;
    adj[5][3] = 2;
    adj[5][4] = 4;

    shortestPaths(adj, short_, 6);
    return 0;
}
