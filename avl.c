
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

int height(node* t)
{
    if(t==NULL)
    {
        return -1;
    }
    int lh=height(t->left);
    int rh=height(t->right);
    if(lh>rh)
    {
        return 1+lh;
    }
    else
    {
        return 1+rh;
    }
}

int balancefactor(node* t)
{
    if(t==NULL)
    {
        return 0;
    }
    int lh=height(t->left);
    int rh=height(t->right);
    return lh-rh;
}

void LL_Rotation(AVL* t, node* nn)
{
    node* a=nn;
    node* b=a->left;
    node* c=b->right;

    b->right=a;
    a->left=c;
    

    b->parent=a->parent;
    if(c)
    {
        c->parent=a;
    }
    if(a->parent&&a==a->parent->left)
    {
        a->parent->left=b;
    }
    else if(a->parent&&a==a->parent->right)
    {
        a->parent->right=b;
    }
    
    a->parent=b;
    if(*t==nn)
    {
        *t=b;
    }
    a->balance_factor=balancefactor(a);
    b->balance_factor=balancefactor(b);

    

}

void LR_Rotation(AVL* t,node* nn)
{
    node* a=nn;
    node* b=a->left;
    node* c=b->right;
    node* cl=c->left;
    node* cr=c->right;

    c->right=a;
    a->left=cr;
    c->left=b;
    b->right=cl;

    c->parent=a->parent;
    if(a->parent && a==a->parent->left)
    {
        a->parent->left=c;
    }
    else if(a->parent && a==a->parent->right)
    {
        a->parent->right=c;
    }
    a->parent=c;
    b->parent=c;
    

    if(cl)
    {
        cl->parent=b;
    }
    if(cr)
    {
        cr->parent=a;
    }

    
    
    a->balance_factor=balancefactor(a);
    b->balance_factor=balancefactor(b);
    c->balance_factor=balancefactor(c);


    if(*t==nn)
    {
        *t=c;
        return;
    }




}

void RR_rotation(AVL* t,node* nn)
{
    node* a=nn;
    node* b=a->right;
    node *bl=b->left;

    b->left=a;
    a->right=bl;

    if(bl)
    {
        bl->parent=a;
    }
    
    if(a->parent && a==a->parent->left)
    {
        a->parent->left=b;
        b->parent=a->parent;
    }
    else if(a->parent && a == a->parent->right)
    {
        a->parent->right=b;
        b->parent=a->parent;
    }
    a->parent=b;
    if(nn==*t)
    {
        b->parent=NULL;
        *t=b;
    }
    a->balance_factor=balancefactor(a);
    b->balance_factor=balancefactor(b);

    

}

void RL_Rotation(AVL* t,node* nn)
{
    node* a=nn;
    node* b=a->right;
    node* c=b->left;
    node* cl=c->left;
    node* cr=c->right;

   c->right=b;
   c->left=a;
   a->right=cl;
   b->left=cr;

   c->parent=a->parent;
   if(a->parent && a==a->parent->left)
   {
       a->parent->left=c;
   }
   else if(a->parent && a==a->parent->right)
   {
       a->parent->right=c;
   }
   b->parent=c;
   a->parent=c;
   

   if(cl)
   {
       cl->parent=a;
   }
   if(cr)
   {
       cr->parent=b;
   }

   a->balance_factor=balancefactor(a);
   b->balance_factor=balancefactor(b);
   c->balance_factor=balancefactor(c);

  

   if(*t==nn)
   {
       *t=c;
       return;
   }

    
}

void init_AVL(AVL* t)
{
    *t=NULL;
    return;
}




void update_balance_factor(AVL t)
{
    if(t==NULL)
    {
        return;
    }
    t->balance_factor=balancefactor(t);
    update_balance_factor((t->left));
    update_balance_factor((t->right));
    
}

void insert_Node(AVL* t, int data, char mon[20])
{
    node* nn=malloc(sizeof(node));
    if(!nn)
    {
        return;
    }
    nn->balance_factor=0;
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    nn->parent=NULL;
    strcpy(nn->month,mon);

    if(*t==NULL)
    {
        *t=nn;
        return;
    }

    node* p=*t;
    node* q=NULL;
    while(p)
    {
        if(data==p->data)
        {
            return;
        }
        else if(data<p->data)
        {
            q=p;
            p=p->left;
        }
        else
        {
            q=p;
            p=p->right;
        }

    }

    nn->parent=q;
    if(data<q->data)
    {
        q->left=nn;
    }
    else
    {
        q->right=nn;
    }
   
    node* x=nn->parent;
    while(x)
    {
        x->balance_factor=balancefactor(x);
        x=x->parent;
    }


    nn=nn->parent;
    
    
    if(nn==NULL)
    {
        return;
    }


    
    while(nn)
    {
        
        if(nn->balance_factor>1||nn->balance_factor<-1)
        {
            if(nn->balance_factor>1 && data<nn->left->data)
            {
                LL_Rotation(t,nn);
                node* y=nn;
                while(y)
                {
                    y->balance_factor=balancefactor(y);
                    y=y->parent;
                }
                nn=nn->parent;
            }

            else if(nn->balance_factor>1&&data>nn->left->data)
            {
                LR_Rotation(t,nn);
                node* y=nn;
                while(y)
                {
                    y->balance_factor=balancefactor(y);
                    y=y->parent;
                }
                nn=nn->parent;
               
            }

            else if(nn->balance_factor<-1&&data>nn->right->data)
            {
                RR_rotation(t,nn);
                node* y=nn;
                while(y)
                {
                    y->balance_factor=balancefactor(y);
                    y=y->parent;
                }
                nn=nn->parent;

            }
            else if(nn->balance_factor<-1 && data<nn->right->data)
            {
                RL_Rotation(t,nn);
                node* y=nn;
                while(y)
                {
                    y->balance_factor=balancefactor(y);
                    y=y->parent;
                }
                nn=nn->parent;
                
            }
        }
        else
        {
            nn=nn->parent;
        }
    }
       
    
    

    return;
    
    


}

void inorder(AVL t)
{
    if(t==NULL)
    {
        return;
    }
    inorder(t->left);
    //printf("\n%s %s %d",t->month,t->data,t->balance_factor);
    if(t->parent==NULL)
    {
        printf("\n%s is Root with balance factor %d ",t->month,t->balance_factor);
    }
    else
    {
        printf("\n%s %s %d ",t->month,t->parent->month,t->balance_factor);
    }
    inorder(t->right);
    return;

}

node* pointersearch(AVL t,int key)
{
    
    AVL p=t;
    while(p)
    {
        if(key==p->data)
        {
            return p;
        }
        else if(key<p->data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    return NULL;


}

void delete_node(AVL* t, int data)
{
    node* p = *t;
    node* q = NULL;
    if(*t==NULL)
    {
        return;
    }
    int flag=0;
    while(p)
    {
        if(p->data==data)
        {
            flag=flag+1;
            break;
        }
        else if(data<p->data)
        {
            q=p;
            p=p->left;
        }
        else
        {
            q=p;
            p=p->right;
        }
    }
    if(flag != 1)
    {
        return;
    }
    
    //Leaf Node
    if(p->left==NULL && p->right==NULL)
    {
        
        if(p->data<q->data)
        {
            q->left=NULL;
            p->parent=NULL;
            
        }
        else
        {
            q->right=NULL;
            p->parent=NULL;
            
        }
        while(q)
        {
            q->balance_factor=balancefactor(q);
            if(q->balance_factor>1 || q->balance_factor <-1)
            {
                if(q->balance_factor<-1 && q->right->left==NULL && q->right->right != NULL)
                {
                    RR_rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left!=NULL && q->right->right==NULL)
                {
                    RL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left!=NULL && q->right->right!=NULL)
                {
                    RL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left !=NULL && q->left->right == NULL)
                {
                    LL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left == NULL && q->left->right != NULL)
                {
                    LR_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left != NULL && q->left->right !=NULL)
                {
                    LL_Rotation(t,q);
                    q=q->parent;
                }

            }
            else
            {
                //q->balance_factor=balancefactor(q);
                q=q->parent;
            }
            
        }
        node* x = *t;
        x->balance_factor=balancefactor(x);
            
        
        return;
        

    }

    //Node with right child only
    if(p->left==NULL && p->right!=NULL)
    {
        if(p->data<q->data)
        {
            q->left=p->right;
            p->right->parent=q;
            free(p);
        }
        else
        {
            q->right=p->right;
            p->right->parent=q;
            free(p);
        }
        while(q)
        {
            q->balance_factor=balancefactor(q);
            if(q->balance_factor>1 || q->balance_factor< -1)
            {
                if(q->balance_factor<-1 && q->right->left == NULL && q->right->right != NULL)
                {
                    RR_rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left != NULL && q->right->right == NULL)
                {
                    RL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left != NULL && q->right->right != NULL)
                {
                    RR_rotation(t,q);
                    q=q->parent;
                }
                else if( q->balance_factor>1 && q->left->left != NULL && q->left->right == NULL)
                {
                    LL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left == NULL && q->left->right !=NULL)
                {
                    LR_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left != NULL && q->left->right != NULL)
                {
                    LR_Rotation(t,q);
                    q=q->parent;
                }
            }
            else
            {
                q=q->parent;
            }
            
        }
        return;
    }

    //Node with left child only
    if(p->left!=NULL && p->right==NULL)
    {
        if(p->data<q->data)
        {
            q->left=p->left;
            p->left->parent=q;
            free(p);
        }
        else 
        {
            q->right=p->left;
            p->left->parent=q;
            free(p);
        }
        while(q)
        {
            q->balance_factor=balancefactor(q);
            if(q->balance_factor>1 || q->balance_factor< -1)
            {
                if(q->balance_factor<-1 && q->right->left == NULL && q->right->right != NULL)
                {
                    RR_rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left != NULL && q->right->right == NULL)
                {
                    RL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor<-1 && q->right->left != NULL && q->right->right != NULL)
                {
                    RR_rotation(t,q);
                    q=q->parent;
                }
                else if( q->balance_factor>1 && q->left->left != NULL && q->left->right == NULL)
                {
                    LL_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left == NULL && q->left->right !=NULL)
                {
                    LR_Rotation(t,q);
                    q=q->parent;
                }
                else if(q->balance_factor>1 && q->left->left != NULL && q->left->right != NULL)
                {
                    LR_Rotation(t,q);
                    q=q->parent;
                }
            }
            else
            {
                q=q->parent;
            }
            
        }
        return;
    }

    //Node with two child 
    if(p->left!=NULL && p->right!=NULL)
    {
        node* r=p;
        node* t2= p;
        r=r->right;
        while(r->left) //Inorder successor
        {
            t2=r;
            r=r->left;
        }
        p->data=r->data;
        strcpy(p->month,r->month);
        t2->left=NULL;
        if(r->right)
        {
            t2->left=r->right;
            r->right->parent=t2;
            r->right=NULL;
            //free(r);
        }
        if(t2==p)
        {
            p->right=r->right;
            r->right->parent=p;
            r->parent=NULL;
            r->right=NULL;
        }
        while(t2)
        {
            t2->balance_factor=balancefactor(t2);
            if(t2->balance_factor>1 || t2->balance_factor< -1)
            {
                if(t2->balance_factor<-1 && t2->right->left == NULL && t2->right->right != NULL)
                {
                    RR_rotation(t,t2);
                    t2=t2->parent;
                }
                else if(t2->balance_factor<-1 && t2->right->left != NULL && t2->right->right == NULL)
                {
                    RL_Rotation(t,t2);
                    t2=t2->parent;
                }
                else if(t2->balance_factor<-1 && t2->right->left != NULL && t2->right->right != NULL)
                {
                    RR_rotation(t,t2);
                    t2=t2->parent;
                }
                else if( t2->balance_factor>1 && t2->left->left != NULL && t2->left->right == NULL)
                {
                    LL_Rotation(t,t2);
                    t2=t2->parent;
                }
                else if(t2->balance_factor>1 && t2->left->left == NULL && t2->left->right !=NULL)
                {
                    LR_Rotation(t,t2);
                    t2=t2->parent;
                }
                else if(t2->balance_factor>1 && t2->left->left != NULL && t2->left->right != NULL)
                {
                    LR_Rotation(t,t2);
                    t2=t2->parent;
                }
            }
            else
            {
                t2=t2->parent;
            }
            
        }
        return;
    }

    

    

}

void delete_subtree(node* t)
{
    if(t==NULL)
    {
        return;
    }
    delete_subtree(t->left);
    delete_subtree(t->right);
    free(t);
    return;
}

void delete_tree(AVL* t)
{
    if(*t==NULL)
    {
        return;
    }
    delete_subtree(*t);
    *t=NULL;
}
