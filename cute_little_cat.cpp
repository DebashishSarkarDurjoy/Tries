#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Node {
public:
    char data;
    bool isTerminal;
    unordered_map<char, Node*> m;

    Node (char c) {
        this->data = c;
        this->isTerminal = false;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie () {
        this->root = new Node('\0');
    }

    Node* getRoot() {
        return this->root;
    }

    void insert(string word) {
        Node *temp = this->root;
        for (char c: word) {
            if (temp->m.find(c) == temp->m.end()) temp->m[c] = new Node(c);
            temp = temp->m[c];
        }
        temp->isTerminal = true;
    }

};

void search_Helper(Trie &t, string &document, int i, unordered_map<string, bool> &output) {
    Node *temp = t.getRoot();

    for (int j = i; j < document.length(); j++) {
        char c = document[j];
        if (temp->m.find(c) == temp->m.end()) return;
        temp = temp->m[c];

        if (temp->isTerminal) {
            string o = document.substr(i, j - i + 1);
            output[o] = true;
        }
    }

}

void documentSearch(string &document, vector<string> &words) {
    Trie t;
    for (string word: words) t.insert(word);

    unordered_map<string, bool> output;
    for (int i = 0; i < document.length(); i++) {
        search_Helper(t, document, i, output);
    }

    for (string word: words) {
        cout << word << " : " << output[word] << endl;
    };
}

int main(void) {
    string document = "little cute cat loves to code in c++, java and python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};

    documentSearch(document, words);

    return 0;
}