<!-- Yay, no errors, warnings, or alerts! -->

<p>
abhakat2, apirani2, jsneh2, shlokm2
</p>
<p>
FINAL PROJECT PROPOSAL
</p>
<p>
<strong><em>LEADING QUESTION</em></strong>
</p>
<p>
How can we use graphs to create a form of naive text-prediction based on the most commonly-succeeding words in a text?
</p>
<p>
<strong><em>HIGH-LEVEL SUMMARY</em></strong>
</p>
<p>
Given any text-based data (books, scripts, transcripts, etc), our program should be able to process the data in such a way that it can “generate” sentences that replicate those of the original text, based on the frequency of predecessor-successor pairs. Data input will be taken as a .txt file, and a CLI will be used for user IO. We’ll parse the words, stripping whitespace, unnecessary punctuation (maybe common prepositions) and convert our .txt into a graph where words connect to succeeding words. These sentences may not have any semantic meaning, but are simply representations of the most commonly chained-together words. This is an interesting experiment in analyzing vocabulary, and word/phrase usage, along with being a form of naive text prediction.
</p>
<p>
<strong><em>DATA ACQUISITION AND PROCESSING</em></strong>
</p>
<ul>

<li><strong>Data Format: </strong>Since our data works with large amounts of text, it makes sense that our input format is just a text file containing words. While the format of the text file doesn’t change, the source does: it should support inputs from any source (i.e. scripts, books, transcripts, and so on). We would search for our large data files through datasets provided by the internet—we have a few linked below—or utilize a web scraper to gather the information ourselves.

<li><strong>Data Correction: </strong>To maintain simplicity, we decided to not worry about punctuation within words - the only punctuation we’ll be considering are commas, periods, exclamation marks, and question marks. Therefore, we’ll have to ensure that any other punctuation is filtered out. We will also need to convert words into lowercase letters, which would serve to enhance the accuracy of the algorithms.

<li><strong>Data Storage: </strong>Our initial graph will be stored as an adjacency list, making it O(V). Each edge struct will contain a start word, an end word, and a weight (representing the amount of times two words are repeated). For our SSSP algorithm, we’ll also need a dictionary to get all potential outputs. This is also an extra O(V) space for each call.

<li><strong>Example/Primary Datasets:</strong> 
<ul>
 
<li><a href="https://github.com/formcept/whiteboard/tree/master/nbviewer/notebooks/data/harrypotter">Harry Potter</a> (primary dataset)
 
<li><a href="https://raw.githubusercontent.com/mxw/grmr/master/src/finaltests/bible.txt">The King James Bible</a> (secondary goal)
 
<li><a href="https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t8.shakespeare.txt">The Complete Works of William Shakespeare</a><span style="text-decoration:underline;"> </span>(secondary goal)
</li> 
</ul>
</li> 
</ul>
<ol>

 Data Preprocessing (txt) 
<ul>
 
<li><strong>Input: </strong>.txt file
 
<li><strong>Output: </strong>Graph representation of text in the file
 
<li><strong>Functionality: </strong>Convert all the text to a directed weighted graph, with nodes representing words and edges representing connections. If there’s an edge that goes from word A to word B, that means that word B immediately succeeded word A at least once. The weight on the edge will be the number of times word B succeeded A.
 
<li><strong>Efficiency: </strong>O(N) time, O(N) space; N = number of words in the text
 
<li><strong>Potential Issues: </strong>non-supported characters, cyclic graphs. 
</li> 
</ul>

<p>
<strong><em>ALGORITHMS:</em></strong>
</p>
 
<li>SSSP (Single-Source Shortest Path) (Graph) 
<ul>
 
<li><strong>Input: </strong>Target word, Length of sentence
 
<li><strong>Output: </strong>Most likely phrase given a particular path length
 
<li><strong>Functionality: </strong>Takes the shortest path (by weight) that visits N nodes from the starting node. If the graph is cyclic (i.e one of the vertices are already visited), then we would ignore the cycle and pick the second largest weight.
 
<li><strong>Efficiency: </strong>O(N) time, O(N) space; N = length of sentence
</li> 
</ul>

<li>Probabilistic weighted sentence generation (Graph) 
<ul>
 
<li><strong>Input: </strong>Target word, Length of sentence
 
<li><strong>Output: </strong>A sentence based on a probabilistic path using the weights connected to a given word
 
<li><strong>Functionality: </strong>Using a starting word, the traversal will traverse through a series of nodes determined randomly based on the edge weights. In this way, more heavily composed components would have a larger probability of being chosen next though it is not given that the most probabilistic sentence would be created. 
</li> 
<li><strong>Efficiency: </strong>O(N) time for greedy approach, O(N) space; N = length of sentence. O(V+E) time for all path solution O(V) space.
</ul>

<li>Breadth-First Traversal (Graph) 
<ul>
 
<li><strong>Input: </strong>Starting Word
 
<li><strong>Output: </strong>Representation of Graph by printing out the word and its corresponding edges.
 
<li><strong>Functionality: </strong>The traversal starts at the starting word, which it displays, and also displays its children along with the weight leading to it. Using a queue, we will add the unvisited nodes to the graph and follow the same algorithm of processing it and then adding its children. We will do this for each of the connected components in order to display our entire word set.
 
<li>O(V + E) time with V = vertices and E = edges, O(V) space (queue).
</li> 
</ul>

<li>Connected Components
<ul>
<li><strong>Input: </strong>Graph

<li><strong>Output: </strong>Set of connected components, Relative Strength of Each Component

<li><strong>Purpose: </strong>Determine the groups of words in each connected component in our given graph. You can also determine the strength of each connected component by using a deterministic metric using the number of nodes and the weights of a given graph. We can do this by summing up the weights of all the edges and dividing it by the number of nodes. 
<li><strong>Efficiency: </strong>O(V+E) time for naive approach, O(V) space; N = length of sentence
<ul>
 
<li>Kosaraju’s algorithm. 
</li> 
</ul>
</ul>
</li> 
</ol>
<p>
<strong><em>TIMELINE:</em></strong>
</p>
<ul>

<li>March 25: Proposal submission.

<li>March 26 to April 1: Proposal confirmation + finding example datasets.

<li>April 2 to April 8: Rudimentary data processing algorithm.

<li>April 9 to April 15: Testing and optimizing data processing algorithm.

<li>April 10 to April 16: Rudimentary implementation of connected components.

<li>April 17 to April 23: Optimizing connected components + rudimentary SSSP algorithm.

<li>April 23 - April 29: Optimizing and compiling all algorithms.

<li>April 29 - May 6: Comprehensive testing, presentation, everything else.
</li>
</ul>
