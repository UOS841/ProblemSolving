#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int to;
	int distance;
};

struct Node {
	bool all_children_visited;
	int max_distance_to_leaf;
	vector<Edge> edges;
};

int find_maximum_diameter(Node &node, vector<Node> &nodes) {
	int first_max_distance_to_leaf = 0;
	int second_max_distance_to_leaf = 0;
	for (Edge& edge : node.edges) {
		// update max_distance_to_leaf
		int distance_to_leaf = edge.distance + nodes[edge.to].max_distance_to_leaf;
		if (distance_to_leaf >= first_max_distance_to_leaf) {
			second_max_distance_to_leaf = first_max_distance_to_leaf;
			first_max_distance_to_leaf = distance_to_leaf;
		} else if (distance_to_leaf > second_max_distance_to_leaf) {
			second_max_distance_to_leaf = distance_to_leaf;
		}
	}
	node.max_distance_to_leaf = first_max_distance_to_leaf;
	return first_max_distance_to_leaf + second_max_distance_to_leaf;
}

int main(void) {
	int V;
	int max_diameter = 0;

	vector<Node> nodes;
	vector<int> visiting_stack;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// init all nodes (index 0 is dummy)
	cin >> V;
	nodes.resize(V + 1);

	// construct tree
	while (--V) {
		int p, c, d;
		cin >> p >> c >> d;
		nodes[p].edges.emplace_back(Edge{c, d});
	}

	// start from the root node
	visiting_stack.emplace_back(1);
	while (!visiting_stack.empty()) {
		Node& node = nodes[visiting_stack.back()];

		// check if children are visited
		if (!node.all_children_visited) {
			node.all_children_visited = true;
			// visit children first
			for (Edge& edge : node.edges) {
				visiting_stack.emplace_back(edge.to);
			}
			continue;
		}

		// if all children are visited,
		// then visit this node
		visiting_stack.pop_back();

		// update maximum diameter
		int diameter = find_maximum_diameter(node, nodes);
		if (diameter > max_diameter) {
			max_diameter = diameter;
		}
	}

	// print the maximum diameter
	cout << max_diameter;

	return 0;
}
