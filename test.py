f = open("parsed_book1.txt", "r").read()
words  = f.split(" ")

graph = {}
counts = {}
prev = ""
for word in words:
    if word == "":
        continue
    if prev == "":
        prev = word
        continue

    if prev not in graph:
        graph[prev] = {word:1}
        counts[prev] = 1
        prev = word
        continue

    if word in graph[prev]:
        graph[prev][word] += 1
    else:
        graph[prev][word] = 1 

    prev = word

print(graph["harry"])


counts = {i:max(graph[i].values()) for i in graph}

# Map : word -> (map adj_word -> weight)

required_length = 5
visited = set()
curr_path = []
max_dist = -1
max_path = []

def backtrack(node, length, dist, visited, curr_path):
    global max_path, max_dist
    if node in visited:
        visited.remove(node)
        return
    
    visited.add(node)

    if (length == required_length):
        if dist > max_dist:
            print(curr_path, dist)
            max_path = curr_path
            max_dist = dist
        visited.remove(node)
        return
    
    for new_node in graph[node]:
        weight = graph[node][new_node]
        if weight < 0.125 * counts[node]:
            continue
        # print(new_node, weight)
        curr_path.append(new_node)
        backtrack(new_node, length + 1, dist + weight, visited, curr_path)
        curr_path.pop()
    if node in visited:
        visited.remove(node)

backtrack("christmas", 0, 0, visited, curr_path)
# print(len(graph["harry"]))
print(max_path)