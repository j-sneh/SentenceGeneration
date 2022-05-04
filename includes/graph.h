#include <unordered_map>
#include <unordered_set>
#include <string>
#include <map>
#include <vector>
#include <queue>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::map;
using std::string;
using std::pair;
using std::queue;


/*
Our predecessor-successor sequence can be represented as the graph shown below
"second" comes after "first" in a phrase
{
    "first": ["second": freq, "second2": freq2...]
    "first1": ["second": freq, "second2", freq2]
}
*/

struct Word {
    string word; // represents the current word
    vector<pair<string, size_t>> adjacents;

    //buckets is calculated through prefix sum + Binary Search
    vector<pair<string, size_t>> buckets;
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
    string HighestWeightSentence(string word, size_t length);
    /* 
    ProbabilisticSentence:
    Takes a given length and uses a random to dictate which word to go to next in a phrase using weighted probability
    */
    string ProbabilisticSentence(string word, size_t length);

    string HighestGreedySentence(string word, size_t length);
    string LowestGreedySentence(string word, size_t length);

    string RandomSentence(string word, size_t length);

    void PrintAdjacents(string word);
    void WriteToCSV(string filename);
    void WriteToCSVRunning(string filename);
    void WriteAsBFS(string filename, string start);

private:
    void BacktrackHelper(const string& word, vector<string>& sentence,size_t weight, size_t length, vector<string>& best_sentence, size_t& best_weight);
    unordered_map< string, Word> graph;
    std::unordered_set<string> visited;
    string SentenceDecoder(const vector<string>& words);
};
