// Harsh Pachauri(25/DA/030)

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare nodes based on frequency
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode)
{
    if (root == NULL)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        huffmanCode[root->ch] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main()
{
    string text;

    cout << "Enter the string: ";
    getline(cin, text);

    // Count frequency of each character
    unordered_map<char, int> freq;

    for (char ch : text)
        freq[ch]++;

    // Min heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a node for each character
    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('\0',
                                 left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    // Generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Display Huffman Codes
    cout << "\nHuffman Codes:\n";

    for (auto pair : huffmanCode)
    {
        cout << pair.first << " : "
             << pair.second << endl;
    }

    // Encode the string
    string encoded = "";

    for (char ch : text)
        encoded += huffmanCode[ch];

    cout << "\nEncoded String:\n";
    cout << encoded << endl;

    return 0;
}