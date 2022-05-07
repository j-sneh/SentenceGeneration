# Sentence Generation with Predecessor-Successor Word Pairs
Final Project for apirani2-shlokm2-abhakat2-jsneh2

Compile the program with `make` in the root directory.

Run it like this: `./bin/exec`

The program runs on a text file that only contains words and numbers and is space-delimited.

Our program delves mostly with the first book of the Harry Potter series, Harry Potter and the Sorcerer's Stone.

Our preprocessor written in `processing/file_cleaner.py` is applied in the source available at this url
 `https://raw.githubusercontent.com/formcept/whiteboard/master/nbviewer/notebooks/data/harrypotter/Book%201%20-%20The%20Philosopher's%20Stone.txt`
though it can be mostly applied to any text.

Our post-processed version of the code is available at `processing/parsed_book.txt`.

Our code compiles the text as a single graph removing any punctuation such that is a single connected component. The graph contains a node as well as directed edges to any word that succeeds it in the text. The adjacency list is a pair that all words that succeed a given word in the text as well as the frequency that it appears.

We explored various methods of generating phrases/sentences of a given path length using various techniques that we listed below.
The traversals we used can be summarized below.
```
    HighestWeightSentence: 
    Takes a given length and returns most likely sentence for said given length
    
    ProbabilisticSentence:
    Takes a given length and uses a random to dictate which word to go to next in a phrase using weighted probability
    
    HighestGreedySentence:
    For each word it takes the word with the highest edge weight and chooses that as the next word until it creates a sentence of length, length
    In case of a tie with edge weights, the word that appears in the text first is chosen.
    
    LowestGreedySentence:
    For each word it takes the word with the least edge weight and chooses the next woord until it creates a sentence of length, length
    In case of a tie with edge weights, the word that appears in the text last  is chosen
    
    Random Sentence:
    Choses words andomly from the adjacency list disregarding the given edge weights until a sentence of length, length, is created
    
    WriteToCSV:
    Creates a CSV that displays each word in the form of"element: " and below each word displays its respective adjancency list sorted from larger
    to lower frequency 
    
    WriteAsBFS:
    Uses a BFS to display the entire graph
    
```
The above descriptions are also documented in our `graph.h` file.

Custom test cases that we wrote to test our implementation can be found on `tests/non_greedy1.txt` and `tests/non_greedy2.txt`.
The test cases are available on `tests/tests.cc` and can be tested by typing `make tests` followed by `./bin/tests` in the terminal in the root folder.

Current Maintainers of the project.
* Shlok Mehrotra (shlokm2)
* Aydan Pirani (apirani2)
* Jonathan Sneh (jsneh2)
* Anay Bhakat (abhakat2)
