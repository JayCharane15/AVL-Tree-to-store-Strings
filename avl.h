#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    char month[20];
    struct node* left;
    struct node* right;
    struct node* parent;
    int balance_factor;
}node;

typedef node* AVL;

int height(AVL t);
int balancefactor(AVL t);

void LL_Rotation(AVL* t, node* nn);
void LR_Rotation(AVL* t, node* nn);
void RR_rotation(AVL* t, node* nn);
void RL_Rotation(AVL* t, node* nn);

void init_AVL(AVL* t);
void insert_Node(AVL *t, int data, char mon[20]);
void update_balance_factor(AVL t);
void inorder(AVL t);
void delete_node(AVL* t,int key);
void delete_subtree(node* t);
void delete_tree(AVL* t);
