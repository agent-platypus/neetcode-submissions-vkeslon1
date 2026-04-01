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

        if(head == nullptr) {
            return nullptr;
        }

        Node* tempOG = head;
        Node* newHead = new Node(tempOG->val);
        Node* tempNew = newHead;
        
        unordered_map<Node*, Node*> OG_CopiedPairs;
        OG_CopiedPairs[tempOG] = tempNew;
        tempOG = tempOG->next;

        while(tempOG != nullptr) {
            Node* newNode = new Node(tempOG->val);
            OG_CopiedPairs[tempOG] = newNode;

            tempOG = tempOG->next;
            tempNew->next = newNode;
            tempNew = newNode;
        }

        tempOG = head; 
        tempNew = newHead;

        while(tempOG != nullptr && tempNew != nullptr) {  
            tempNew->random = OG_CopiedPairs[tempOG->random];
            tempOG = tempOG->next;
            tempNew = tempNew->next;
        }

        return newHead;
        
    }
};
