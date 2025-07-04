#include "RecommendedConcession.h"
#include <limits>
#include <iostream>

RecommendedConcession::RecommendedConcession(const StadiumGraph& graph) : graph(graph) {}

std::string RecommendedConcession::recommendBest(const std::string& seat, int& totalTime) const {
    std::string bestConcession = "None";
    totalTime = std::numeric_limits<int>::max();

    int bestWalkTime = std::numeric_limits<int>::max();
    int bestWaitTime = std::numeric_limits<int>::max();

    // For specified seat and each concession calculate total wait time (walk time + wait time)
    for (const std::string& concession : graph.getAllConcessions()) {
        
        // Get walk total walk time from specified seat to current concession
        int walk = graph.dijkstra(seat, concession);
        

        // In the case a concession is not reachable
        if(walk == INT_MAX) continue; 

        // Get wait time for current concession
        int wait = graph.getQueueTime(concession);

        // Calculate total time from specified seat to current concession
        int combined = walk + wait;
        
        // Output total time for specified seat and current concession
        std::cout << "\n";
        std::cout << seat << " → " << concession
                  << " | Walk: " << walk << ", Wait: " << wait
                  << " → Total: " << combined << "\n";

        // Determine best route from specified seat to a concession
        if (combined < totalTime || (combined == totalTime && walk < bestWalkTime)||
            (combined == totalTime && walk == bestWalkTime && wait < bestWaitTime)) {
            totalTime = combined;
            bestWalkTime = walk;
            bestWaitTime = wait;
            bestConcession = concession;
        }
    }

    // Return best concession to got to from specified seat
    return bestConcession;
}
