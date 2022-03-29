### Grade
Not Yet Competent (70%)

Missing traversal algorithm, and no clarity on how the graph should be structured. Resubmit penalty will apply.
### Comments
Leading question and proposal are not in sync. The traversal algorithm is missing. There is one flaw in Datasets, and in Algorithms too. 

**Leading Question**
The leading question is interesting but at odds with the description. Identification of most commonly used words is less challenging than text prediction. The leading question and the rest of the proposal should be on the same lines. 

**Dataset**
The dataset is vague, and it is not immediately clear how copy-righted text can be obtained. Please include links to actual source text to be used in the project. Preprocessing is missing out filtering out common words (is/of/the etc) that occur the most in texts and can heavily skew such graphs. It is also not immediately clear how the weights would be assigned while building the graphs, and whether the edges are directed or undirected.

**Algorithm**
The algorithm section is missing the traversal algorithm. Secondly, the cycle detection algorithm would work for directed graphs (leading from my comments in Datasets). How would you handle the situation where to words can follow each other? (each way, the way each etc.)