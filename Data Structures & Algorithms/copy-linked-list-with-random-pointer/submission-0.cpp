/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> store_rand;

        while(temp != nullptr) {
            Node* new_node = new Node(temp->val);
            store_rand[temp] = new_node;
            temp = temp->next;
        }

        temp = head;

        while(temp != nullptr) {
            Node* copy = store_rand[temp];
            copy->next = store_rand[temp->next];
            copy->random = store_rand[temp->random];
            temp = temp->next;
        }

        return store_rand[head];

    }
};
