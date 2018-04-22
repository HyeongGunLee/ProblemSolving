#include <iostream>
using namespace std;


int N;

struct Node {
    char left;
    char right;
};

struct Node arr[100];

void preorder(char a) {
    cout << a;
    if (arr[a].left != '.') {
        preorder(arr[a].left);
    }
    if (arr[a].right != '.') {
        preorder(arr[a].right);
    }
}

void postorder(char a) {
    if (arr[a].left != '.') {
        postorder(arr[a].left);
    }
    if (arr[a].right != '.') {
        postorder(arr[a].right);
    }
    cout << a;
}


void inorder(char a) {
    if (arr[a].left != '.') {
        inorder(arr[a].left);
    }
    cout << a;
    if (arr[a].right != '.') {
        inorder(arr[a].right);
    }
}


int main(void) {
    cin >> N;
    char name, left, right;
    for (int i = 0; i < N; i++) {
        cin >> name >> left >> right;
        arr[name].left = left;
        arr[name].right = right;
    }
    preorder('A');
    cout<<endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
}