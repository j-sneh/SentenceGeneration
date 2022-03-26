abhakat2, apirani2, jsneh2, shlokm2

# FINAL PROJECT PROPOSAL

## LEADING QUESTION
How can we use graphs to identify semantic patterns within a text-based corpus?

## HIGH-LEVEL SUMMARY
Given any text-based data (books, scripts, transcripts, etc), our program should be able to preprocess the data in such a way that it can “generate” sentences that replicate those of the corpus, based off the frequency of predecessor-successor pairs. Data input will be taken as a .txt file, and a CLI will be used for user IO. We’ll use a data processing algorithm to convert our .txt into a graph, Floyd’s algorithm to check for valid inputs, and a SSSP algorithm to determine  the “most typical” sentence starting from a given word. These sentences may not have any semantic meaning, but are simply representations of the most commonly chained-together words. This is an interesting experiment in analyzing vocabulary, and word/phrase usage, along with being a form of naive text prediction.

## DATA ACQUISITION AND PROCESSING
### Data Format: 
Since our data works with large amounts of text, it makes sense that our input format is just a text file containing words. While the format of the text file doesn’t change, the source does: it should support inputs from any source (i.e. scripts, books, transcripts, and so on).
### Data Correction: 
In order to maintain simplicity, we decided to not worry about punctuation within words - the only punctuation we’ll be considering are commas, periods, exclamation marks, and question marks. Therefore, we’ll have to ensure that any other punctuation is filtered out. We will also need to convert words into lowercase letters, which would serve to enhance the accuracy of the algorithms.
### Data Storage: 
Our initial graph will be stored as an adjacency list, making it O(V). Each edge struct will contain a start word, an end word, and a weight (representing the amount of times two words are repeated). For our SSSP algorithm, we’ll also need a dictionary to get all potential outputs. This is also an extra O(V) space for each call.
### Example/Primary Datasets:
Harry Potter (.txt file from books).
The King James Bible
The Complete Works of William Shakespeare

## GRAPH ALGORITHMS:
### Data Preprocessing
Input: .txt file
Output: Graphical representation of text in the file
Functionality: Convert all the text to a directed weighted graph, with nodes representing words and edges representing connections, with the weight representing the amount of times this repetition happens. We will also have designated “end” nodes, to represent punctuation and indicate the ending of a sentence. 
Efficiency: O(N) time, O(N) space; N = number of words in the text
Potential Issues: non-supported characters, cyclic graphs. 

### Floyd’s Cycle Detection Algorithm
Input: Graph
Output: Boolean (whether or not the graph is cyclic)
Functionality: Ensure that the input data that we get isn’t acyclic, which would mess with our traversals. Performed as a simple 2 pointer approach.
Efficiency: O(N) time, O(1) space; N = number of unique words + punctuation

### SSSP (Single-Source Shortest Path)
Input: Target word
Output: Most likely sentence
Functionality: Takes the shortest path from the given input to any punctuation within its connected component. If the graph is cyclic, we’d ensure that cyclic branches are never taken.
Efficiency: O(V^2) time for naive approach, O(V) space; V = number of vertices/words in graph

## TIMELINE:
March 25: Proposal submission.
March 26 to April 1: Proposal confirmation + finding example datasets.
April 2 to April 8: Rudimentary data processing algorithm.
April 9 to April 15: Testing and optimizing data processing algorithm.
April 10 to April 16: Rudimentary implementation of Floyd’s.
April 17 to April 23: Optimizing Floyd + rudimentary SSSP algorithm.
April 23 - April 29: Optimizing all algorithms and putting them together.
April 29 - May 6: Comprehensive testing, presentation, everything else.
