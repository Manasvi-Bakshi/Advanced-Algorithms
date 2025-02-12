#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void insertionSort(Node*& head) {
    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next;
        if (!sorted || sorted->value >= current->value) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 8);
    insert(head, 4);
    insert(head, 5);
    insert(head, 2);
    insert(head, 9);
    insert(head, 1);

    insertionSort(head);
    print(head);

    return 0;
}
