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

        unordered_map<Node*, Node*> ogCopyPairs;
        
        if (head == nullptr) {
            return nullptr;
        }

        Node* temp = head;
        Node* newNode = new Node(temp->val);
        

        Node* newHead = newNode; // need to save the head of the new list
        Node* currNew = newHead;

        ogCopyPairs[temp] = newNode;

        temp = temp->next;

        while(temp != nullptr) {
            Node* newNode = new Node(temp->val);

            ogCopyPairs[temp] = newNode;

            currNew->next = newNode;
            currNew = currNew->next;
            temp = temp->next;
        }

        // for(Node* tmp = newHead; tmp != nullptr; tmp = tmp->next) {
        //     cout << "node val = " << tmp->val << endl;
        // }
        
        temp = head;
        currNew = newHead;

        while(temp != nullptr) {
            if (temp->random == nullptr) {
                currNew->random = nullptr;
            }
            else {
                currNew->random = ogCopyPairs[temp->random];
            }
            currNew = currNew->next;
            temp = temp->next;
        }

        return newHead;
      
    }
};
