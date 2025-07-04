#include "Stadium.h"
#include <queue>
#include <limits>
#include <unordered_set>
#include <algorithm>

void StadiumGraph::addEdge(const std::string& from, const std::string& to, int weight) {
    adjList[from].emplace_back(to, weight);
    adjList[to].emplace_back(from, weight); // bidirectional
}

// Member function to add a concession to a stadium
void StadiumGraph::addConcession(const std::string& name) {
    concessions.push_back(name);
}

// Accessing all concessions of a stadium
std::vector<std::string> StadiumGraph::getAllConcessions() const {
    return concessions;
}

// Setting the queue time for a concession
void StadiumGraph::setQueueTime(const std::string& concession, int time) {
    queueTimes[concession] = time;
}

// Getting current queue time for a concession
int StadiumGraph::getQueueTime(const std::string& concession) const {
    if (queueTimes.find(concession) != queueTimes.end()) {
        return queueTimes.at(concession);
    }
    return std::numeric_limits<int>::max();
}

// Implementation of Dijkstra's algorithm to find the quickest path from a seat to a concession in a stadium
int StadiumGraph::dijkstra(const std::string& start, const std::string& end) const {
    
    // Map to store shortest path to each node
    std::unordered_map<std::string, int> dist;

    // Minimum priority queue to select the next closest node
    std::priority_queue<
        std::pair<int, std::string>,
        std::vector<std::pair<int, std::string>>,
        std::greater<>> priQueue;

    // Initialize all distances
    for (const auto& node : adjList) {
        dist[node.first] = std::numeric_limits<int>::max();
    }

    // Initialize start node to a distance of 0
    dist[start] = 0;
    priQueue.emplace(0, start);

    // Examine the stadium graph
    while (!priQueue.empty()) {
    std::pair<int, std::string> currentItem = priQueue.top();
    priQueue.pop();

    int cost = currentItem.first;
    std::string node = currentItem.second;

    if (node == end) return cost;

    for (const auto& neighborPair : adjList.at(node)) {
        const std::string& neighbor = neighborPair.first;
        int weight = neighborPair.second;

        int newCost = cost + weight;

        // Check if new path is shorter
        if (newCost < dist[neighbor]) {

            // New path is shorter, update and push onto queue
            dist[neighbor] = newCost;
            priQueue.emplace(newCost, neighbor);
        }
    }
}

    return std::numeric_limits<int>::max(); // No path found
};