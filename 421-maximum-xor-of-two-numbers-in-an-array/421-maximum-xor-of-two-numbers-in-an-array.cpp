class Node {
private:
    Node *child[2];

public:
    Node() {
        child[0] = child[1] = NULL;
    }
    
    bool isNull(const bool &childID) {
        return child[childID] == NULL;
    }
    
    Node *extend(const bool &childID) {
        if( isNull(childID) ) {
            child[childID] = new Node;
        }
        return child[childID];
    }
    
    Node *get(const bool &childID) {
        return child[childID];
    }
};

class Trie {
    Node *root;
    
public:
    Trie() {
        root = new Node;
    }
    
    void clear_(Node *curNode) {
        if( curNode == NULL ) {
            return;
        }
        clear_(curNode -> get(0));
        clear_(curNode -> get(1));
        delete( curNode );
        curNode = NULL;
    }
    
    void clear() {
        clear_(root);
    }
    
    void insert(const int &mask) {
        Node *curNode = root;
        for(int i = 30; i >= 0; --i) {
            curNode = curNode -> extend(mask>>i&1);
        }
    }
    
    int getMaxXor(const int &num) {
        int curXor = 0;
        Node *curNode = root;
        for(int i = 30; i >= 0; --i) {
            if( curNode -> isNull(num>>i&1^1) ) {
                curNode = curNode -> get(num>>i&1);
            }
            else {
                curNode = curNode -> get(num>>i&1^1);
                curXor |= 1<<i;
            }
        }
        return curXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie suffexMask;
        for(int &num : nums) {
            suffexMask.insert(num);
        }
        int bestXor = 0;
        for(int &num : nums) {
            bestXor = max(bestXor, suffexMask.getMaxXor(num));
        }
        suffexMask.clear();
        return bestXor;
    }
};