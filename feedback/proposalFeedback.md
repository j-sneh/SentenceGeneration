### Grade
Not Yet Competent (70%) [This commit does not imply regrading]


### Comments
I am really interested in the project idea but the proposal has a a few major and minor flaws that need to be addressed. Since I missed mentioning about the Leading Question in my previous feedback, I will consider this as an informal feedback so that double penalty for resubmission does not apply. Please go through the specific comments in the three sections below, carefully.

**Leading Question**
The leading question is interesting but does not explain how the algorithms will be used to achieve the goal. How would you apply SSSP and weighted sentence generation, and connect different algorithms to achieve this goal? Leading question should connect how the algorithms would be used. Secondly, you can merge Leading Question and High Level Summary together (I am reviewing considering the High Level Summary as part of Leading Question, else the Leading Question is very sparse.)

**Dataset**
Preprocessing is missing out filtering out common words (is/of/the etc) that occur the most in texts and can heavily skew such graphs (this is quite common in a lot of NLP algorithms - think about what has to be a threshold frequency beyond which a word is too common). Your description indicates "start word and end word", do you mean the graph is directed? Finally, do you have an upper limit to how many words you want to contain in your graph? There can be a large number of unique words in such large bodies of work - which is more of a system design concern when building a graph.

**Algorithm**
I am confused why SSSP would be O(N) -- Do you mean Dijkstra here? Or you mean a greedy next-node selection at any point in the graph looking at the edge weights? In which case, you may want to rename the algorithm to something else. 