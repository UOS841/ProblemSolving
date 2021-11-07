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
            // 입력을 받으면서 할당한다.
			int i = Integer.parseInt(s);

			Node node = new Node(i);

			if (tree.root == null)
                // 루트가 비어있다면, 입력값이 Root
				tree.root = node;
			else
                // 루트가 있다면, 비교할당
				VLR2tree(tree.root, node);

		}

		tree2LRV(tree.root);
	}

	static void VLR2tree(Node p, Node n) {
		if (n.key < p.key) {
            // Node의 값이 Parent의 값보다 작다면, 왼쪽에 할당한다.
			if (p.lNode == null) {
                // Left가 비어있다면 할당
				p.lNode = n;
				return;
			} else {
                // Left에 자식이 있다면 비교 할당
				VLR2tree(p.lNode, n);
			}
		} else if (n.key > p.key) {
            // Node의 값이 Parent의 값보다 크다면, 오른쪽에 할당한다.
			if (p.rNode == null) {
                // Right가 비어있다면 할당
				p.rNode = n;
				return;
			} else {
                // Right에 자식이 있다면 비교 할당
				VLR2tree(p.rNode, n);
			}
		}
        // Node와 Parent의 값이 같은 경우는 없음
	}

	static void tree2LRV(Node node) {
        // print left child node 
		if (node.lNode != null)
			tree2LRV(node.lNode);

        // print right child node 
		if (node.rNode != null)
			tree2LRV(node.rNode);

        // print root node 
		System.out.println(node.key);
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
            // right child 없으면 right
			rNode = n;
		} else {
            // right child 있으면 left
			lNode = n;
		}
	}
}