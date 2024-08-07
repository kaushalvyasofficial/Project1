/*Write a c++ program to implement Huffman coding text compression algorithm.
 Build the huffman Tree using characters and their frequencies input from 
 user. Encode a given string by using codes generated from huffman tree and 
 decode the bit sequence entered by the user. */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node *left, *right;
    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->frequency > r->frequency;
    }
};

// Function to build Huffman Tree and return the root
Node* buildHuffmanTree(unordered_map<char, int>& freqmap) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a leaf node for each character and add it to the min heap
    for (auto it : freqmap) {
        minHeap.push(new Node(it.first, it.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() != 1) {
        // Extract the two minimum frequency nodes from the min heap
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with these two nodes as children and with a frequency equal to the sum of their frequencies
        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        // Add the new node to the min heap
        minHeap.push(newNode);
    }
    // The root of the Huffman Tree is the only node left in the min heap
    return minHeap.top();
}

// Function to traverse the Huffman Tree and generate Huffman Codes
void generateHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr)
        return;

    // If the node is a leaf node, then it contains a character and its code
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    // Traverse left
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);

    // Traverse right
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a given string using Huffman Codes
string encode(string text, unordered_map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }
    return encodedText;
}

// Function to decode the bit sequence using Huffman Tree
string decode(Node* root, string encodedText) {
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        // If it's a leaf node, append the character to the decoded text and reset to root
        if (!current->left && !current->right) {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    // Frequency map of characters
    unordered_map<char, int> freqmap = {
        {'A', 12},
        {'B', 15},
        {'C', 7},
        {'D', 13},
        {'E', 9}
    };

    // Build the Huffman Tree
    Node* root = buildHuffmanTree(freqmap);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto it : huffmanCodes) {
        cout << it.first << " : " << it.second << endl;
    }

    // Encode a given string
    string text = "ABCDE";
    string encodedText = encode(text, huffmanCodes);
    cout << "\nEncoded Text: " << encodedText << endl;

    // Decode the encoded text
    string decodedText = decode(root, encodedText);
    cout << "Decoded Text: " << decodedText << endl;

    return 0;
}
