def TSP(g, n, c, visited, s):
    if len(visited) == n:
        return g[c][s], visited + [s]

    min_cost = float('inf')
    min_path = None
    for x in range(n):
        if x != s and x not in visited:
            visited.append(x)
            cost, path = TSP(g, n, x, visited, s)
            total_cost = g[c][x] + cost
            if total_cost < min_cost:
                min_cost = total_cost
                min_path = path
            visited.pop()

    return min_cost, min_path

n = int(input("Enter number of vertices: "))
print("Enter the adjacency matrix:")
g = []
for i in range(n):
    g.append(list(map(int, input().split())))

k = 0
visited = [k]
min_cost, min_path = TSP(g, n, k, visited, k)
print("Minimum cost for TSP:", min_cost)
print("Path:", min_path)