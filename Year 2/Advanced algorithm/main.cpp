#include <iostream>
#include <algorithm>
#include "./Linked-list/singlyLinklist.hpp"
using namespace std;

void Insert(nodePtr& head, int data);
int main()
{
    nodePtr head;
    head = new Node;
    head->data = 10;
    head->next;

    nodePtr last;
    last = new Node;
    last->data = 30;
    last->next = NULL;

    //Output
    //cout << head->data << endl;

    Insert(head, 30);
    
    nodePtr tmp;
    tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }

    return 0;
}

void Insert(nodePtr& head, int data)
{
    nodePtr tempPtr;
    tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->next = NULL;
    head = tempPtr;

}
