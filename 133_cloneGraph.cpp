#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int val)
    {
        val = val;
        neighbors = vector<Node*>();
    }
    Node(int val, vector<Node*> n)
    {
        val = val;
        neighbors = n;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL)
            return NULL;
        
        Node* copy = new Node(node->val);
        /* to make a note of visited nodes */
        mp[node] = copy;

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            //remove added node and push its neighbors
            Node* curr = q.front();
            q.pop();

            for(int i=0; i<(curr->neighbors).size(); i++)
            {
                Node* neighbor = curr->neighbors[i];
                if(mp.find(neighbor) == mp.end())
                {
                    /* if not found then insert */
                    Node* temp = new Node(neighbor->val);
                    q.push(neighbor);
                    mp[neighbor] = temp;
                }
                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> mp;
};

int main()
{

    
    cout << endl << "La fin!\n" << endl;
}