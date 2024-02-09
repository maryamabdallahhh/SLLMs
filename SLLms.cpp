using namespace std;
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
   /// / first ques
     ~LinkedList() {
        while (head) {
            Node* current = head->next;
            delete head;
            head = current;
        }
    }
     ////second ques
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // third ques
    void deleteFront() {
        if (head == nullptr) {
           cout << "List is empty. Cannot delete from an empty list." <<  endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int Length() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }
    Node* get__nth(int n) {
        int cnt = 0;
        for(Node* cur =head;;cur =cur->next)
            if(cnt++==n)
                return cur;
    }
    ///ques 4
    Node* get__nthBack(int n) {
        if (Length() < n)
            return nullptr;
        return get__nth(Length() -n+1);
    }
    /////////////////ques5
    bool IsSame(const LinkedList& other) {
        Node* h1 = head, *h2 = other.head;
        while (h1 && h2) {
            if (h1->data != h2->data)
                return false;
            h1 = h1->next, h2 = h2->next;
        }
        return !h1 && !h2;
    }
    /////ques 6  Linked List without tail/length
    void AddElement(int value) {
        Node* item = new Node(value);
        item->next = head;
        head = item;
    }
    Node* getTail() {
        if (!head)
            return nullptr;
        Node* cur = head;
        for (;cur->next;cur = cur->next)
            return cur;

    }
    ////homework 2
    ////ques 1
    void deleteNextNode(Node* node) {
        Node* toDelete = node->next;
        node->next = node->next->next->next;
        delete (toDelete);
    }
    void deleteNodeWithKey(int value) {
        if (!Length())
            cout << "empty list" << endl;
        else if (head->data == value)
            deleteFront();
        else {
            for (Node* cur = head, *prv = nullptr;cur;prv = cur, cur = cur->next) {
                if (cur->data == value) {
                    deleteNextNode(prv);
                    return;
                }
            }
            cout << "Value not found";
        }
    }
    ///ques 2
    void SwapPairs() {
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->next) {
                swap(cur->data, cur->next->data);
                cur = cur->next;
            }
        }
    }
    ///ques3
    void Reverse() {
        if (Length() <= 1)
            return;
        tail = head;
        Node* prv = head;
        head = head->next;
            while (head) {
                Node* next = head->next;
                head->next = prv;
                prv = head;
            }
            head = prv;
            tail->next = nullptr;
    }
    ///ques 4
    void DeleteEvenPositions() {
        if (Length() <= 1)
            return;
   
    for (Node* cur = head->next, *prv = head;cur;) {
        deleteNextNode(prv);
        if (!prv->next)
            break;
        cur = prv->next->next;
        prv = prv->next;
    }
    }
    ///ques 5
    void Insertsorted(int value) {
        if (!Length() || value <= head->data)
            insertFront(value);
        else {
            for (Node* cur = head, *prv = nullptr;cur;prv = cur, cur->next) {
                if (value <= cur->data) {
                    embed_after(prv, value);
                    break;
                }
            }
        }
    }



    void display() {
        Node* temp = head;
        while (temp != nullptr) {
             cout << temp->data << " ";
            temp = temp->next;
        }
         cout << endl;
    }
};
 
      
int main()
{
 }

 