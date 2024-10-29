#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
typedef Node* nodePtr;

void Insert(nodePtr& head, int data);
void Delete(nodePtr& head, int data);

int main() {
    nodePtr head = nullptr;
    Insert(head, 10);
    Insert(head, 20);
    Insert(head, 30);

    cout << "Original List: ";
    nodePtr tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;

    // Deleting node with data 20
    Delete(head, 20);

    cout << "List after deleting 20: ";
    tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

void Insert(nodePtr& head, int data) {
    nodePtr tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->next = nullptr;

    if (head == nullptr) {
        head = tempPtr;
    } else {
        nodePtr last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = tempPtr;
    }
}

void Delete(nodePtr& head, int data) {
    if (head == nullptr) return;

    // If head node itself holds the data to be deleted
    if (head->data == data) {
        nodePtr temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Search for the node to be deleted, keep track of the previous node
    nodePtr prev = head;
    nodePtr curr = head->next;

    while (curr != nullptr && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    // If the data was not found in the list
    if (curr == nullptr) return;

    // Unlink the node from the list
    prev->next = curr->next;
    delete curr;
}
