#include<iostream>
using namespace std;

class mBST {

    struct node {
        int data1;
        int data2;
        int data3;
        node* left;
        node* mid1;
        node* mid2;
        node* right;
    };

    node* root;

    node* insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data1 = x;
            t->left = t->right = t->mid1 = t->mid2 = NULL;
        }
        //case1
        else if (x < t->data1)
            t->left = insert(x, t->left);
        //case2
        else if (x > t->data1 && x < t->data2)
            t->mid1 = insert(x, t->mid1);
        //case4
        else if (x > t->data2 && x < t->data3)
            t->mid2 = insert(x, t->mid2);
        //case3
        else if (x > t->data1)
            t->right = insert(x, t->right);
        
        return t;
    }


    void inorder(node* t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data1 << " ";
        inorder(t->mid1);
        inorder(t->mid2);
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        //case1
        else if (x < t->data1)
            return find(t->left, x);
        //case2
        else if (x > t->data1 && x < t->data2)
            return find(t->mid1, x);
        //case3
        else if (x > t->data2 && x < t->data3)
            return find(t->mid2, x);
        //case4
        else if (x > t->data3)
            return find(t->right, x);
        else
            return t;
    }

public:
    mBST() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }


    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    mBST t;
    //60, 30, 90, 10, 50, 80, 100, 20, 40, 70, 39, 38, 37, 36, 35, 34, 33, 32
    t.insert(60);
    t.insert(30);
    t.insert(90);
    t.insert(10);
    t.insert(50);
    t.insert(80);
    t.insert(100);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(39);
    t.insert(38);
    t.insert(36);
    t.insert(35);
    t.insert(34);
    t.insert(33);
    t.insert(32);
    t.display();
    return 0;
}