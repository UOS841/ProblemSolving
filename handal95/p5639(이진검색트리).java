import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int ans;
	static Tree tree;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		tree = new Tree();
		String s = "";
		while ((s = br.readLine()) != null && s.length() != 0) {
			int i = Integer.parseInt(s);

			Node node = new Node(i);

			if (tree.root == null)
				tree.root = node;
			else
				VLR2tree(tree.root, node);

		}

		tree2LRV(tree.root);
	}

	static void VLR2tree(Node p, Node n) {

		if (n.key < p.key) {
			if (p.lNode == null) {
				p.lNode = n;
				return;
			} else {
				VLR2tree(p.lNode, n);
			}
		} else if (n.key > p.key) {
			if (p.rNode == null) {
				p.rNode = n;
				return;
			} else {
				VLR2tree(p.rNode, n);
			}
		}
	}

	static void tree2LRV(Node node) {

		if (node.lNode != null)
			tree2LRV(node.lNode);
		if (node.rNode != null)
			tree2LRV(node.rNode);

		System.out.println(node.key);

	}
}

class Tree {
	Node root;

	public Tree() {
		this.root = null;
	}
}

class Node {
	int key;
	Node rNode;
	Node lNode;

	public Node(int i) {
		this.key = i;
		this.rNode = null;
		this.lNode = null;
	}

	public void add(Node n) {
		if (this.rNode == null) {
			rNode = n;
		} else {
			lNode = n;
		}
	}
}