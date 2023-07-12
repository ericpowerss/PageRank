#ifndef PAGERANK_ADJACENCYLIST_H
#define PAGERANK_ADJACENCYLIST_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

class AdjacencyList
{
private:
    map<string, vector<string>> outDegree;
    map<string, vector<string>> inDegree;
    map<string, double> rank;
    map<string, double> rankTemp;
    set<string> uniqueUrls;


public:
    void insertVertex(string from, string to);
    void pageRank(int powerIterations);
};

void AdjacencyList::insertVertex(string from, string to)
{

    uniqueUrls.insert(from);
    uniqueUrls.insert(to);

    outDegree[from].push_back(to);
    if (outDegree.find(to) == outDegree.end())
    {
        outDegree[to] = {};
    }

    inDegree[to].push_back(from);
    if (inDegree.find(from) == inDegree.end())
    {
        inDegree[from] = {};
    }

}

void AdjacencyList::pageRank(int powerIterations)
{

    // Logic for if power iteration is 1
    for (auto url : uniqueUrls)
    {
        rank[url] = 1.0 / uniqueUrls.size();

    }

    powerIterations--;
    rankTemp = rank;


    // Logic for if power iteration is greater than 1
    while (powerIterations > 0)
    {


        for (auto url : uniqueUrls)
        {
            double score = 0.0;

            for (auto vertexPointingIn : inDegree[url])
            {

                // Makes sure I am not dividing by zero, solves problem with vertices with indegree of 0
                if (outDegree[vertexPointingIn].size() == 0)
                {
                    rankTemp[url] = 0.0;
                }

                // Actual calculation for updating rank
                else
                {
                    score += rank[vertexPointingIn] / outDegree[vertexPointingIn].size();

                }

            }

            rankTemp[url] = score;

        }

        // Update variables used within loops
        rank = rankTemp;
        powerIterations--;

    }

    // Print statement that
    for (auto it = rank.begin(); it != rank.end(); ++it) {
        cout << it->first << " " << fixed << setprecision(2) << it->second << endl;
    }

}

#endif //PAGERANK_ADJACENCYLIST_H
