#include <iostream>

using namespace std;

// Inorder   : left -> root  -> right
// Postorder : left -> right -> root

// Preorder  : root -> left  -> right
typedef struct Tree *TreePointer;
typedef struct Tree {
    int root;
    TreePointer left;
    TreePointer right;
} Tree;

int arr[2][100001];

void Preorder(Tree *TreePointer) {
    if (TreePointer) {
        cout << TreePointer->root << " ";
        Preorder(TreePointer->left);
        Preorder(TreePointer->right);
    }
}

void Inorder(Tree *TreePointer) {
    if (TreePointer) {
        Inorder(TreePointer->left);
        Inorder(TreePointer->right);
        cin >> TreePointer->root;
    }
}

void Postorder(Tree *TreePointer) {
    if (TreePointer) {
        Postorder(TreePointer->left);
        cin >> TreePointer->root;
        Postorder(TreePointer->right);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    // for (int k = 0; k < 2; k++) {
    //     for (int i = 0; i < n; i++) {
    //         cin >> arr[k][i];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     cout << 
    // }
    Tree trees[n+1];

    for (int i = 1; i <=n; i++) {
        trees[i].root = i;
        trees[i].left = NULL;
        trees[i].right = NULL;

    }

    for (int i = 2; i<= n; i++) {
        if (i % 2 == 0) {
            trees[i/2].left = &trees[i];
        }
        else{
            trees[i/2].right = &trees[i];
        }
    }

    Inorder(&trees[1]);
    //Postorder(&trees[1]);
    Preorder(&trees[1]);


    // int n; cin >> n;
    // for (int i = 0; i < n; i++) {
    //     Inorder(&TreePointer);
    //     Postorder(&TreePointer);
        
    // }
    // for (int i = 0; i < n; i++) {
    //     Preorder(&TreePointer);
    // }
    
    return 0;
}


// 1 2 3
// 1 3 2

//     2
// 1       3

//           1
//     2           3
// 4       5   6       7


// 4 2 5 1 6 3 7
// 4 5 2 6 7 3 1

// 1 2 4 5 3 6 7


//         2
//     1       3
// 4       5

// 4 1 5 2 3
// 4 5 1 3 2

// 2 1 4 5 3

// // Inorder   : left -> root  -> right
// // Postorder : left -> right -> root

// // Preorder  : root -> left  -> right