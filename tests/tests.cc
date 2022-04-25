#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "graph.h"
#include <iostream>
#include <string>

TEST_CASE("Non greedy test case check", "Trivial Examples") {
  // SECTION("Can use sections") {}
  // clang-format off

  SECTION("Checking Size 1"){
    string test;
    Graph g ("tests/non_greedy.txt");
    test = g.HighestWeightSentence("hello", 1);
    std::cout << test << std::endl;
    REQUIRE(test == "hello.");
    test = g.HighestWeightSentence("my", 1);
    std::cout << test << std::endl;
    REQUIRE(test == "my.");
    test = g.HighestWeightSentence("dear", 1);
    std::cout << test << std::endl;
    REQUIRE(test == "dear.");
  }
  SECTION("More complex examples"){
    string test;
    Graph g ("tests/non_greedy.txt");
    test = g.HighestWeightSentence("hello", 2);
    std::cout << test << std::endl;
    REQUIRE(test == "hello my.");
    test = g.HighestWeightSentence("lovely", 2);
    std::cout << test << std::endl;
    REQUIRE(test == "lovely people.");
    test = g.HighestWeightSentence("lovely", 3);
    std::cout << test << std::endl;
    REQUIRE(test == "lovely.");
  }
  
  
}