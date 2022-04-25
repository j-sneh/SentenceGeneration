#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "graph.h"
#include <iostream>

TEST_CASE("Non greedy test case check", "Highest Weighted Sentence Check") {
  // SECTION("Can use sections") {}
  // clang-format off
  Graph g ("non_greedy.txt");
  g.WriteToCSV("result.txt");
  
}