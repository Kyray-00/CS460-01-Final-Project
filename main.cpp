#include "Stadium.h"
#include "RecommendedConcession.h"
#include <iostream>

void runTest(const std::string& testName, StadiumGraph& stadium, const std::string& seat, const std::string& expected){
    
    std::cout << "\n" << testName << "\n";

    RecommendedConcession recommender(stadium);
    
    // Define placeholder for total time from specified seat to concession
    int WalkAndWaitTime;
    std::string best = recommender.recommendBest(seat, WalkAndWaitTime);

    // Output result of recommended concession to go to
    std::cout << "Expected: " << expected << " , Got: " << best << " (Total time: " << WalkAndWaitTime << " mins)\n";

    if(best == expected){
        std::cout << "Test Passed\n";
    }
    else {
        std::cout << "Test Failed\n";
    }
    
}

void test1(){
    StadiumGraph stadium;

    // Graph structure from a point to a point
    // Test Case: Chooses shortest wait time regardless of distance (e.g. Longer walk but shorter wait time)
    stadium.addEdge("Seat1", "node11", 1);
    stadium.addEdge("node11", "node12", 2);
    stadium.addEdge("node12", "Concession1", 2);
    stadium.addEdge("node11", "Concession2", 7);
    stadium.addEdge("Seat1", "Concession3", 5); 

    // Concessions
    stadium.addConcession("Concession1");
    stadium.addConcession("Concession2");
    stadium.addConcession("Concession3");

    // Queue times
    stadium.setQueueTime("Concession1", 3);
    stadium.setQueueTime("Concession2", 2);
    stadium.setQueueTime("Concession3", 1);

    runTest("Test Case 1: Pick Shortest Wait Time", stadium, "Seat1", "Concession3");
}

void test2(){
    StadiumGraph stadium;

    // Test Case: Disconnected Concession or Dead end
    stadium.addEdge("Seat2", "node21", 2);
    stadium.addEdge("node21", "Concession1", 5);

    // Concessions
    stadium.addConcession("Concession1");
    stadium.addConcession("Concession2");

    // Queue times
    stadium.setQueueTime("Concession1", 3);
    stadium.setQueueTime("Concession2", 2);

    runTest("Test Case 2: Disconnected concession", stadium, "Seat2", "Concession1");
}

void test3(){
    StadiumGraph stadium;

    // Test Case: returns the best concession based on shortest path if total time is tied
    stadium.addEdge("Seat3", "node31", 4);
    stadium.addEdge("node31", "node32", 3);
    stadium.addEdge("node32", "Concession1", 1);
    stadium.addEdge("node31", "Concession2", 2);
    stadium.addEdge("Seat3", "Concession3", 7);

     // Concessions
    stadium.addConcession("Concession1");
    stadium.addConcession("Concession2");
    stadium.addConcession("Concession3");


    // Queue times
    stadium.setQueueTime("Concession1", 2);
    stadium.setQueueTime("Concession2", 4);
    stadium.setQueueTime("Concession3", 3);

    runTest("Test Case 3: If tied total time return shortest distance time", stadium, "Seat3", "Concession2");
}
int main() {
    test1();
    test2();
    test3();
    return 0;
}

