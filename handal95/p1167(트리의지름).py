import re
import itertools
from sys import stdin


def run(testcase=1):
    for _ in range(testcase):
        solve()


def inputs():
    """
    2 <= V <= 100,000
    """
    V = int(stdin.readline())

    distancs = [[-1 for _ in range(V)] for _ in range(V) ]
    for v in range(V):
        # 정점 번호, 간선 정보, 정점 번호, 정점 거리
        infos = list(map(int, stdin.readline().split()))[:-1]
        node_u = infos[0] -1 
        length = len(infos[1:]) // 2
        
        infos = infos[1:]
        for idx in range(length):
            node_v = infos[2 * idx] - 1
            distance = infos[2 * idx + 1]
            
            distancs[node_u].append(nodev) = distance
            distancs[node_v][node_u] = distance
        
    return V, distancs


def solve():
    V, dist_matrix = inputs()
    
    # def get_tree_radius(root=0):
    #     queue = [root]
    #     while len(queue) > 0:
    #         node_u = queue.pop(0)

    #         for node_v in range(V):
    #             U2V = dist_matrix[node_u][node_v]
    #             if U2V < 0:
    #                 continue
                
    #             for node_x in range(V):
    #                 U2X = dist_matrix[node_u][node_x]
    #                 V2X = dist_matrix[node_v][node_x]
    #                 if V2X < 0 or node_u == node_x:
    #                     continue

    #                 if U2X < 0 or U2X > (U2V + V2X):
    #                     queue.append(node_v)
    #                     U2X = U2V + V2X
    #                     dist_matrix[node_u][node_x] = U2X
    #                     dist_matrix[node_x][node_u] = U2X
        
    #     return dist_matrix[root].index(max(dist_matrix[root]))

    # v = get_tree_radius()
    # u = get_tree_radius(v)
    
    print(dist_matrix[v][u])
    
run()
