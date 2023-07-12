#include <iostream>
#include <string>
#include "AdjacencyList.h"

using namespace std;

int main() {

    int numLines, powerIterations;
    string from, to, line, stringNumLines, stringPowerIterations;
    AdjacencyList graph;

    // Create first string stream object
    getline(cin, line);
    stringstream sso(line);

    // Gets amount of lines needed to read
    getline(sso, stringNumLines, ' ');
    numLines = stoi(stringNumLines);

    // Gets the amount of power iterations
    getline(sso, stringPowerIterations);
    powerIterations = stoi(stringPowerIterations);

    // While number of lines is not 0, keep reading lines
    while(numLines--)
    {

        // Create second string stream object
        getline(cin, line);
        stringstream sso2(line);

        // Gets the values for from and to
        getline(sso2, from, ' ');
        getline(sso2, to);
        // Inserts new vertex into adjacency list
        graph.insertVertex(from, to);

    }

    graph.pageRank(powerIterations);

    return 0;

}

