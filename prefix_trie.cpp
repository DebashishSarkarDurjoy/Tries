#include <iostream>
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

class Trie {
private:
    Node* root;

public:
    Trie() {
        this->root = new Node('\0');
    }

    void insert(string word) {
        Node *temp = this->root;
        for (char c: word) {
            if (temp->m.count(c) == 0) {
                Node* newNode = new Node(c);
                temp->m[c] = newNode;
            }
            temp = temp->m[c];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node *temp = this->root;
        for (char c: word) {
            if (temp->m.count(c) == 0) return false;
            temp = temp->m[c];
        }
        return temp->isTerminal;
    }
};

int main(void) {
    string words[] = {"apple", "ape", "no", "new", "not", "never"};

    Trie t;
    for (string word: words) {
        t.insert(word);
    }

    int q;
    cin >> q;

    while (q--) {
        string search_word;
        cin >> search_word;

        if (t.search(search_word)) cout << "Found" << endl;
        else cout << "Not Found" << endl;
    }
    
    return 0;
}