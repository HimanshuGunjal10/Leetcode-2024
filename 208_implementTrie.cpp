#include<iostream>
using namespace std;

class Node
{
public:
    bool isWord;
    Node* next[26]; //! missed this 26 leading to segmentation fault
    Node()
    {
        isWord = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
};

class Trie
{
public:
    Node* trieNode;
    Trie()
    {
        trieNode = new Node();
    }
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};

void Trie::insert(string word)
{
    Node* curr = trieNode;
    // for loop implemenation
    for(int i=0; i<word.length(); i++)
    {
        if(curr->next[word[i] - 'a'] == NULL)
            curr->next[word[i] - 'a'] = new Node();
        curr = curr->next[word[i] - 'a'];
    }
    curr->isWord = true;
}

bool Trie::search(string word)
{
    Node* it = trieNode;
    // while loop implemantation
    int i = 0;
    while(i < word.length())
    {
        if(it->next[word[i] - 'a'] == NULL)
            return false;
        it = it->next[word[i] - 'a'];
        i++;
    }
    return it->isWord;
}

bool Trie::startsWith(string prefix)
{
    Node* it = trieNode;
    int i = 0;
    while(i < prefix.length())
    {
        if(it->next[prefix[i] - 'a'] == NULL)
            return false;
        it = it->next[prefix[i] - 'a'];
        i++;
    }
    return true;
}

int main()
{
    Trie* myTrie = new Trie();
    myTrie->insert("rambo");
    myTrie->insert("johnny");
    cout << "Results for johnny, ram, ramboy, krish, john:\n";
    cout << " " << myTrie->search("johnny");
    cout << " " << myTrie->search("ram");
    cout << " " << myTrie->search("ramboy");
    cout << " " << myTrie->search("krish");
    cout << " " << myTrie->startsWith("john");

    cout << "\nLa Fin! \n";
    return 0;
}