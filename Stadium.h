#ifndef STADIUM_H
#define STADIUM_H

#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

class StadiumGraph {
public:
    void addEdge(const std::string& from, const std::string& to, int weight);
    int dijkstra(const std::string& start, const std::string& end) const;
    std::vector<std::string> getAllConcessions() const;
    void addConcession(const std::string& name);
    void setQueueTime(const std::string& concession, int time);
    int getQueueTime(const std::string& concession) const;

private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjList;
    std::unordered_map<std::string, int> queueTimes;
    std::vector<std::string> concessions;
};

#endif