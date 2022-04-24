f = open("parsed_book1.txt", "r").read()
words  = f.split(" ")

graph = {}
prev = ""
for word in words:
    if word == "":
        continue
    if prev == "":
        prev = word
        continue

    if prev not in graph:
        graph[prev] = {word:1}
        prev = word
        continue

    if word in graph[prev]:
        graph[prev][word] += 1
    else:
        graph[prev][word] = 1 

    prev = word

print(graph["harry"])

# Map : word -> (map adj_word -> weight)

#  

required_length = 5
visited = set()
curr_path = []
max_dist = -1
max_path = []

def backtrack(node, length, dist, visited, curr_path):
    if node in visited:
        visited.remove(node)
        return
    
    visited.add(node)
    print(curr_path, dist)

    if (length == required_length):
        if dist > max_dist:
            max_path = curr_path
        visited.remove(node)
        return
    
    for new_node in graph[node]:
        weight = graph[node][new_node]
        # print(new_node, weight)
        curr_path.append(new_node)
        backtrack(new_node, length + 1, dist + weight, visited, curr_path)
        curr_path.pop()
    if node in visited:
        visited.remove(node)

backtrack("harry", 0, 0, visited, curr_path)
print(max_path)