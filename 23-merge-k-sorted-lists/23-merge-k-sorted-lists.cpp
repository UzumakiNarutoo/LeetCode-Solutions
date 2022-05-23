/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void update(ListNode* &curNode, priority_queue<pair<int, ListNode*>> &heads) {
        ListNode *minNode = heads.top().second;
        heads.pop();
        curNode->val = minNode->val;
        if(minNode->next != nullptr) {
            heads.push({-minNode->next->val, minNode->next});
        }
        if(heads.size()) {
            curNode->next = new ListNode;
            curNode = curNode->next;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> heads;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                heads.push({-lists[i]->val, lists[i]});
            }
        }
        if(heads.empty()){
            return nullptr;
        }
        ListNode* newList = new ListNode;
        ListNode* curNode = newList;
        while(heads.size()) {
            update(curNode, heads);
        }
        return newList;
    }
};