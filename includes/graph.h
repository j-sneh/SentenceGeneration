#include <unordered_map>
#include <string>

using std::unordered_map;
using std::string;


/*
Our predecessor-successor sequence can be represented as the graph shown below
"second" comes after "first" in a phrase
{
    "first": {"second": freq, "second2": freq2...}
    "first1": {"second": freq, "second2", freq2}
}
*/

struct Word {
    string word; // represents the current word
    unordered_map<string, int> adjacents;
    int highest_weight;
};

class Graph {
public:
    /*
    Graph:
    Generates the graph object given a filename
    */
    Graph(std::string filename);
    /*
    HighestWeightSentence: 
    Takes a given length and returns most likely sentence for said given length
    */
    string HighestWeightSentence(int length);
    /* 
    ProbabilisticSentence:
    Takes a given length and uses a random to dictate which word to go to next in a phrase using weighted probability
    */
    string ProbabilisticSentence(int length);
    void ReadGraph();
    void PrintAdjacents(string word);

private:

    unordered_map< string, Word> graph;

};