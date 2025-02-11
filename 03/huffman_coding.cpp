#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

struct Node {
    char ch;
    int f;
    Node *l, *r;
    Node(char ch, int f) : ch(ch), f(f), l(NULL), r(NULL) {}
};

struct MinHeap {
    int sz, cap;
    Node** arr;
    MinHeap(int cap) : sz(0), cap(cap), arr(new Node*[cap]) {}
};

void swap(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* h, int i) {
    int sm = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < h->sz && h->arr[l]->f < h->arr[sm]->f) sm = l;
    if (r < h->sz && h->arr[r]->f < h->arr[sm]->f) sm = r;
    if (sm != i) {
        swap(&h->arr[i], &h->arr[sm]);
        minHeapify(h, sm);
    }
}

Node* extractMin(MinHeap* h) {
    Node* t = h->arr[0];
    h->arr[0] = h->arr[h->sz - 1];
    --h->sz;
    minHeapify(h, 0);
    return t;
}

void insertMinHeap(MinHeap* h, Node* n) {
    int i = h->sz++;
    while (i && n->f < h->arr[(i - 1) / 2]->f) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = n;
}

MinHeap* buildMinHeap(char d[], int f[], int n) {
    MinHeap* h = new MinHeap(n);
    for (int i = 0; i < n; i++) h->arr[i] = new Node(d[i], f[i]);
    h->sz = n;
    for (int i = (n - 2) / 2; i >= 0; --i) minHeapify(h, i);
    return h;
}

Node* buildHuffmanTree(char d[], int f[], int n) {
    MinHeap* h = buildMinHeap(d, f, n);
    while (h->sz > 1) {
        Node *l = extractMin(h), *r = extractMin(h);
        Node* t = new Node('$', l->f + r->f);
        t->l = l;
        t->r = r;
        insertMinHeap(h, t);
    }
    return extractMin(h);
}

void printCodes(Node* root, vector<int>& path) {
    if (!root) return;
    if (!root->l && !root->r) {
        cout << root->ch << ": ";
        for (int b : path) cout << b;
        cout << "\n";
    }
    path.push_back(0);
    printCodes(root->l, path);
    path.pop_back();
    path.push_back(1);
    printCodes(root->r, path);
    path.pop_back();
}

void HuffmanCodes(char d[], int f[], int n) {
    Node* root = buildHuffmanTree(d, f, n);
    vector<int> path;
    printCodes(root, path);
}

int main() {
    char d[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int f[] = { 5, 9, 12, 13, 16, 45 };
    int n = sizeof(d) / sizeof(d[0]);
    HuffmanCodes(d, f, n);
    return 0;
}
