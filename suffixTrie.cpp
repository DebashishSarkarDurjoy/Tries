#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;

    Node(char data) {
        this->data = data;
        this->isTerminal = false;
    }
};

class SuffixTrie {
private:
    Node *root;

    void insert_helper(string word) {
        Node *temp = this->root;

        for (char c: word) {
            if (temp->m.count(c) == 0) {
                Node *newNode = new Node(c);
                temp->m[c] = newNode;
            }
            temp = temp->m[c];
        }
        temp->isTerminal = true;
    }

public:
    SuffixTrie() {
        this->root = new Node('\0');
    }

    bool search(string word) {
        Node *temp = this->root;

        for (char c: word) {
            if (temp->m.count(c) == 0) return false;
            temp = temp->m[c];
        }

        return temp->isTerminal;
    }

    void insert(string word) {
        for (int i = 0; word[i] != '\0'; i++) {
            this->insert_helper(word.substr(i));
        }
    }

};

int main(void) {
    string words[] = {"apple", "ape", "always", "mango", "banana", "lettuce", "capsicum", "chilli", "melon"};
    string word = "hello";

    SuffixTrie t;
    t.insert(word);
    // Trie t;
    // for (string word: words) {
    //     t.insert(word);
    // }

    string input = "";
    do {
        cin >> input;
        cout << (t.search(input) ? "Found" : "Not Found") << endl;
    } while (input != "!");

    return 0;
}