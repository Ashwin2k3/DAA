#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for Huffman tree
struct HuffmanNode {
    char data; // Character
    int freq; // Frequency
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }
};

// Comparator for priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* const& node1, HuffmanNode* const& node2) {
        return node1->freq > node2->freq;
    }
};

// Function to build Huffman tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    // Create nodes for each character and push them into minHeap
    for (const auto& pair : freqMap) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        minHeap.push(node);
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* mergeNode = new HuffmanNode('$', left->freq + right->freq);
        mergeNode->left = left;
        mergeNode->right = right;
        minHeap.push(mergeNode);
    }

    return minHeap.top();
}

// Function to traverse Huffman tree and generate codes
void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to perform Huffman encoding
string huffmanEncode(const string& input) {
    unordered_map<char, int> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(freqMap);

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    string encodedString = "";
    for (char c : input) {
        encodedString += huffmanCodes[c];
    }

    return encodedString;
}

int main() {
    string input = "Huffman coding is a data compression algorithm.";
    
    cout << "Initial string: " << input << endl;

    string encodedString = huffmanEncode(input);

    cout << "Encoded string: " << encodedString << endl;

    return 0;
}

