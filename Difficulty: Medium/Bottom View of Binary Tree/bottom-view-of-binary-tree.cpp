/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        
        //map for mapping in order also handy for negative index
        map<int,int>mp;
        //queue as we will use bfs;
        queue<pair<Node* ,int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            Node* node = curr.first;
            int hd = curr.second;
            
            mp[hd]= node->data;
            
            if(node->left){
                q.push({node->left,hd-1});
            }
            if(node->right){
                q.push({node->right,hd+1});
            }
        
            
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};