#ifndef RECOMMENDEDCONCESSION_H
#define RECOMMENDEDCONCESSION_H

#include "Stadium.h"
#include <string>

class RecommendedConcession {
public:
    RecommendedConcession(const StadiumGraph& stadium);

    std::string recommendBest(const std::string& seat, int& totalTime) const;

private:
    const StadiumGraph& graph;
};

#endif
