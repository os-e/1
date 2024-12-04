#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void quick_sort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    srand(time(nullptr));
    int pivot_index = left + rand() % (right - left + 1);
    int pivot = arr[pivot_index], i = left;
    swap(arr[pivot_index], arr[right]);
    for (int j = left; j < right; ++j)
        if (arr[j] < pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[right]);

    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main()
{
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    quick_sort(arr, 0, arr.size() - 1);
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomisedSelect(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];
    srand(time(nullptr));
    int pivot_index = left + rand() % (right - left + 1);
    int pivot = arr[right], i = left;
    swap(arr[pivot_index], arr[right]);
    for (int j = left; j < right; j++)
        if (arr[j] < pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[right]);

    if (k == i)
        return arr[k];
    return k < i ? randomisedSelect(arr, left, i - 1, k) : randomisedSelect(arr, i + 1, right, k);
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 7, 6, 3};
    int k = 2;
    cout << "The " << k << "th smallest element is: " << randomisedSelect(arr, 0, arr.size() - 1, k - 1) << endl;
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph
{
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back(Edge(src, dest, weight));
    }
};

int findParent(vector<int> &parent, int i)
{
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
};

void kruskalMST(vector<Edge> &edges, int V, int E)
{
    vector<Edge> result;
    int e = 0;
    int i = 0;

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int v = 0; v < V; ++v)
        parent[v] = v;

    while (e < V - 1 && i < E)
    {
        Edge next_edge = edges[i++];

        int x = findParent(parent, next_edge.src);
        int y = findParent(parent, next_edge.dest);

        if (x != y)
        {
            result.push_back(next_edge);
            unionSets(parent, rank, x, y);
            e++;
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto &edge : result)
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
};

int main()
{
    int V = 4;
    int E = 5;
    Graph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    kruskalMST(g.edges, V, E);

    return 0;
}#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int val): data(val){}
};

class Tree {
public:
    TreeNode* root;

    Tree(int rootVal) {
        root = new TreeNode(rootVal);
    }

    void insert(TreeNode* parent, int childVal) {
        if (!parent) return;
        TreeNode* childNode = new TreeNode(childVal);
        parent->children.push_back(childNode);
    }

    bool search(TreeNode* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        
        for (TreeNode* child : node->children)
            if (search(child, val)) 
                return true;
        return false;
    }

    void printTree(TreeNode* node, int level = 0) {
        if (!node) return;
        
        for (int i = 0; i < level; ++i) cout << "  "; 
        cout << "|--" << node->data << endl;
        
        for (TreeNode* child : node->children)
            printTree(child, level + 1);
        
    }
};

int main() {
    Tree tree(1);  
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 3);
    tree.insert(tree.root->children[0], 4);
    tree.insert(tree.root->children[0], 5);
    tree.insert(tree.root->children[1], 6);
    tree.insert(tree.root->children[1], 7);
    tree.insert(tree.root->children[0]->children[0], 8);
    tree.insert(tree.root->children[0]->children[0], 9);
    tree.insert(tree.root->children[0]->children[1], 10);
    tree.insert(tree.root->children[0]->children[1], 11);
    tree.insert(tree.root->children[1]->children[0], 12);
    tree.insert(tree.root->children[1]->children[0], 13);
    tree.insert(tree.root->children[1]->children[1], 14);
    tree.insert(tree.root->children[1]->children[1], 15);

    cout << "Tree Structure:" << endl;
    tree.printTree(tree.root);

    cout << "\nSearch for 14: " << (tree.search(tree.root, 14) ? "Found" : "Not Found") << endl;
    cout << "Search for 18: " << (tree.search(tree.root, 18) ? "Found" : "Not Found") << endl;

    return 0;
}#include <iostream>
#include <vector>
using namespace std;

void computeFailureFunction(const string &pattern, vector<int> &f)
{
    int m = pattern.length();
    f[0] = 0;
    int j = 0;
    int i = 1;

    while (i < m)
        if (pattern[i] == pattern[j])
            f[i++] = ++j;
        else if (j != 0)
            j = f[j - 1];
        else
            f[i++] = 0;
}

void KMPsearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> f(m);
    computeFailureFunction(pattern, f);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
            i++, j++;
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            // return;
            j = f[j - 1];
        }
        else if (pattern[j] != text[i])
            if (j != 0)
                j = f[j - 1];
            else
                i++;
    }
}

int main()
{
    string text = "abacaabaccabacabaabb";
    string pattern = "abacab";

    KMPsearch(text, pattern);

    return 0;
}#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class SuffixTrieNode {
public:
    unordered_map<char, SuffixTrieNode*> children;
    vector<int> indexes;

    void insertSuffix(const string& suffix, int index) {
        indexes.push_back(index);
        if (!suffix.empty()) {
            char firstChar = suffix[0];
            if (children.find(firstChar) == children.end()) {
                children[firstChar] = new SuffixTrieNode();
            }
            children[firstChar]->insertSuffix(suffix.substr(1), index);
        }
    }
};

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class SuffixTrieNode {
public:
    unordered_map<char, SuffixTrieNode*> children;
    vector<int> indexes;

    void insertSuffix(const string& suffix, int index) {
        indexes.push_back(index);
        if (!suffix.empty()) {
            char firstChar = suffix[0];
            if (children.find(firstChar) == children.end()) {
                children[firstChar] = new SuffixTrieNode();
            }
            children[firstChar]->insertSuffix(suffix.substr(1), index);
        }
    }

    void printNode(int level = 0) {
        for (auto& child : children) {
            for (int i = 0; i < level; ++i) cout << "  ";
            cout << "|-- '" << child.first << "' -> " << "[";
            for (size_t j = 0; j < child.second->indexes.size(); ++j) {
                cout << child.second->indexes[j];
                if (j < child.second->indexes.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
            child.second->printNode(level + 1);
        }
    }
};

class SuffixTrie {
public:
    SuffixTrieNode* root;

    SuffixTrie(const string& text) {
        root = new SuffixTrieNode();
        for (int i = 0; i < text.length(); ++i) {
            root->insertSuffix(text.substr(i), i);
        }
    }

    vector<int> search(const string& pattern) {
        SuffixTrieNode* currentNode = root;
        for (char ch : pattern) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return {};
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->indexes;
    }

    void printTrie() {
        root->printNode();
    }
};

int main() {
    string text = "banana";
    SuffixTrie trie(text);

    cout << "Suffix Trie Structure:" << endl;
    trie.printTrie();

    string pattern = "ana";
    vector<int> result = trie.search(pattern);

    if (!result.empty()) {
        cout << "Pattern found at indexes: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge
{
public:
	int src, dest, weight;
	Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph
{
public:
	int V, E;
	vector<Edge> edges;
	Graph(int V, int E) : V(V), E(E) {}

	void addEdge(int src, int dest, int weight)
	{
		edges.push_back(Edge(src, dest, weight));
	}
};

void bellmanFord(const vector<Edge> &edges, int V, int src)
{
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;

	for (int i = 1; i < V ; ++i)
	{
		for (const auto &edge : edges)
		{
			int u = edge.src;
			int v = edge.dest;
			int weight = edge.weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	for (const auto &edge : edges)
	{
		int u = edge.src;
		int v = edge.dest;
		int weight = edge.weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			cout << "Graph contains negative weight cycle\n";
			return;
		}
	}
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < V; ++i)
		cout << i << "\t\t" << dist[i] << "\n";
}

int main()
{
	int V = 5;
	int E = 5;

	Graph g(V, E);

	g.addEdge(1, 3, 2);
	g.addEdge(4, 3, -1);
	g.addEdge(2, 4, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(0, 1, 5);

	int src = 0;
	bellmanFord(g.edges, V, src);

	return 0;
}
#include <iostream>
using namespace std;

class BTreeNode {
public:
    bool leaf;
    int keyTally;
    int keys[4]; // M-1 = 5-1 = 4 keys
    BTreeNode* pointers[5]; // M = 5 pointers

    BTreeNode(bool leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(int k);
};

BTreeNode::BTreeNode(bool leaf) {
    this->leaf = leaf;
    this->keyTally = 0;
    for (int i = 0; i < 5; i++) {
        this->pointers[i] = nullptr;
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = keyTally - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        keyTally++;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (pointers[i + 1]->keyTally == 4) { // M - 1 = 4
            splitChild(i + 1, pointers[i + 1]);
            if (keys[i + 1] < k)
                i++;
        }
        pointers[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->keyTally = 2; // M / 2 - 1 = 5 / 2 - 1 = 2

    for (int j = 0; j < 2; j++)
        z->keys[j] = y->keys[j + 3]; // M / 2 = 3

    if (!y->leaf) {
        for (int j = 0; j < 3; j++)
            z->pointers[j] = y->pointers[j + 3];
    }

    y->keyTally = 2;
    for (int j = keyTally; j >= i + 1; j--)
        pointers[j + 1] = pointers[j];

    pointers[i + 1] = z;
    for (int j = keyTally - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[2];
    keyTally++;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keyTally; i++) {
        if (!leaf)
            pointers[i]->traverse();
        cout << " " << keys[i];
    }

    if (!leaf)
        pointers[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < keyTally && k > keys[i])
        i++;

    if (i < keyTally && keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return pointers[i]->search(k);
}

class BTree {
    BTreeNode* root;

public:
    BTree() {
        root = new BTreeNode(true);
    }

    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    BTreeNode* search(int k) {
        if (root == nullptr)
            return nullptr;
        else
            return root->search(k);
    }

    void insert(int k);
};

void BTree::insert(int k) {
    if (root->keyTally == 4) { // M - 1 = 4
        BTreeNode* s = new BTreeNode(false);
        s->pointers[0] = root;
        s->splitChild(0, root);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        s->pointers[i]->insertNonFull(k);
        root = s;
    } else
        root->insertNonFull(k);
}

int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed B-Tree is:";
    t.traverse();

    int k = 6;
    cout << "\nSearching for " << k << ": " << (t.search(k) ? "Present" : "Not Present");

    k = 15;
    cout << "\nSearching for " << k << ": " << (t.search(k) ? "Present" : "Not Present");

    return 0;
}
