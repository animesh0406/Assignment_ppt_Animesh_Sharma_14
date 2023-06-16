#include<bits/stdc++.h>
using namespace std;
/*
<aside>
💡 **Question 1**

Given a linked list of **N** nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

</aside>
*/
struct Node {
    int key;
    struct Node* next;
};

void detectAndRemoveLoop(Node* head)
{
    if (head == NULL || head->next == NULL)
        return;
 
    Node *slow = head, *fast = head;
 
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast) {
        slow = head;
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
 
    fast->next = NULL;
    }
}

/*
<aside>
💡 **Question 2**

A number **N** is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

**Example 1:**

</aside>
*/
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
 Node* reverseList(struct Node* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        auto rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
    Node* addOne(Node *head) 
    {
        Node* l = reverseList(head);
        int carr = 0;
        Node* ans = new Node(0);
        Node* curr = ans;
        bool z = true;
        while(l or carr != 0){
            int x = l ? l->data : 0;
            int y = z ? 1 : 0;
            int sum = x + y + carr;
            z = false;
            curr->next = new Node(sum%10);
            carr = sum/10;
            curr = curr->next;
            l = l ? l->next : NULL;
        }
        return reverseList(ans->next);
}



/*
<aside>
💡 **Question 3**

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:(i) a **next** pointer to the next node,(ii) a **bottom** pointer to a linked list where this node is head.Each of the sub-linked-list is in sorted order.Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. **Note:** The flattened list will be printed using the bottom pointer instead of next pointer.

</aside>
*/
class Node {
public:
    int data;
    Node *right; 
    Node *down;
};
 
Node* head = NULL;
Node* merge(Node* a, Node* b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }
 
    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
 
Node* flatten(Node* root)
{

    if (root == NULL || root->right == NULL)
        return root;
    root->right = flatten(root->right);
    root = merge(root, root->right);
    return root;
}



/*
<aside>
💡 **Question 4**

You are given a special linked list with **N** nodes where each node has a next pointer pointing to its next node. You are also given **M** random pointers, where you will be given **M** number of pairs denoting two nodes **a** and **b**  **i.e. a->arb = b** (arb is pointer to random node)**.**

Construct a copy of the given list. The copy should consist of exactly **N** new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes **X** and **Y** in the original list, where **X.arb** **-->** **Y**, then for the corresponding two nodes **x** and **y** in the copied list, **x.arb --> y.**

</aside>

*/

struct Node {
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};
 
Node* cloneLinkedList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
     
    // Step 1: Create new nodes and insert them next to the original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
     
    // Step 2: Set the random pointers of the new nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = head;
    Node* clonedHead = head->next;
    Node* clonedCurr = clonedHead;
    while (clonedCurr->next != NULL) {
        curr->next = curr->next->next;
        clonedCurr->next = clonedCurr->next->next;
        curr = curr->next;
        clonedCurr = clonedCurr->next;
    }
    curr->next = NULL;
    clonedCurr->next = NULL;
     
    return clonedHead;
}
 

 /*
 <aside>
💡 **Question 5**

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return *the reordered list*.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

**Example 1:**

</aside>
 */

  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
          return NULL;
        ListNode* o=NULL;//for traversing and connecting odd index nodes
        ListNode* es=NULL;     //for linking last odd node to first even index node
        ListNode* ee=NULL;     //for traversing and connecting even index node
        ListNode* curr=head;   //for traversing original linked list
        int count=1;           //for checking even and odd index
        while(curr!=NULL){
            if(count&1){
                if(o==NULL){
                    o=curr;
                }
                else{
                    o->next=curr;
                    o=o->next;
                }
            }
            else if(count%2==0){
                if(es==NULL){
                    es=curr;
                    ee=curr;
                }
                else{
                    ee->next=curr;
                    ee=ee->next;
                }
            }
            count++;
            curr=curr->next;
        }
        o->next=es;
        if(ee!=NULL)
           ee->next=NULL;
        return head;
}


/*
<aside>
💡 **Question 6**

Given a singly linked list of size **N**. The task is to **left-shift** the linked list by **k** nodes, where **k** is a given positive integer smaller than or equal to length of the linked list.

</aside>
*/

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0) return head;
        
        ListNode* cur = head;
        int len =1;
        while(cur->next){
            len++;
            cur=cur->next;
        }
        cur->next=head;
        k=k%len;
        k = len-k;
        while(k--)
            cur=cur->next;
        
        head=cur->next;
        cur->next=NULL;
        
        return head;
}


/*
<aside>
💡 **Question 7**

You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `ith` node (**1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] = 0`.

</aside>
*/
vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head!=NULL){
            ll.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        vector<int>ans(ll.size());
        for(int i = 0; i<ll.size(); i++){
            while(!st.empty() && ll[i]>ll[st.top()]){
                int kid = st.top();
                st.pop();
                ans[kid] = ll[i];
            }
            st.push(i);
        }
    return ans;
}


/*
<aside>
💡 **Question 8**

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

</aside>
*/
ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL and head->val==0){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*dummy=new ListNode(0);
        ListNode*cur=head;
        dummy->next=cur;
        ListNode*temp=dummy;
        while(cur!=NULL){
            ListNode*next=cur->next;
             if(cur->val==0 and next==NULL){
                temp->next=NULL;
                return dummy->next;
            
            }
            else if(cur->val==0 and next!=NULL){
                temp->next=cur->next;
                cur=next;
            }
            else{
                int sum=0;
                sum+=cur->val;
                bool yes=false;
                while(next!=NULL){
                    sum+=next->val;
                    if(sum==0){
                        yes=true;
                        break;
                    }
                    else{
                         next=next->next;
                    }

                }
                if(yes){
                    temp->next=next->next;
                    cur=temp;
                }
                else{
                    temp=cur;
                    cur=cur->next;
                }
            }
        }   
        return dummy->next;
}

