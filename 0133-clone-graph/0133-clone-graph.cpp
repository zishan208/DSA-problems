/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;

        Node* cloneRoot = new Node(node->val); 
        map<Node*,Node*> copy;
        queue<Node*> q;
        q.push(node);
        copy[node]=cloneRoot;

        while(!q.empty()){

            Node* temp=q.front();
            q.pop();

            for(auto it: temp->neighbors){
               

                if(copy.find(it)==copy.end()){
                     Node* cloneneg = new Node(it->val);
                     copy[it]=cloneneg;
                     q.push(it);

                }

                copy[temp]->neighbors.push_back(copy[it]);



              
            }

           
        }
        return cloneRoot;
        
    }
};