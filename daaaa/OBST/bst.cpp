#include<cstdio>
#include<iostream>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *create();
void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);
struct tree *create()
{
    struct tree *p,*root;
    int m,x;
    char s;
    root=(struct tree *)malloc(sizeof(struct tree));
    printf("\nenter the value of the main root");
    scanf("%d",&m);
    root->data=m;
    root->left=NULL;
    root->right=NULL;
    printf("\nenter n to stop creation of the binary search tree");
    fflush(stdin);
    scanf("%c",&s);
    while(s!='n')
    {
        p=root;
        printf("\nenter the value of the newnode");
        fflush(stdin);
        scanf("%d",&x);
        while(1)
        {
            if(x<p->data)
            {
                if(p->left==NULL)
                {
                    p->left=(struct tree *)malloc(sizeof(struct tree));
                    p=p->left;
                    p->data=x;
                    p->right=NULL;
                    p->left=NULL;
                    break;
                }
                else
                p=p->left;
            }
            else
            {
                if(p->right==NULL)
                {
                    p->right=(struct tree *)malloc(sizeof(struct tree));
                    p=p->right;
                    p->data=x;
                    p->right=NULL;
                    p->left=NULL;
                    break;
                }
                else
                p=p->right;
            }
        }
        printf("\nwant to continue");
        fflush(stdin);
        scanf("%c",&s);
    }
    return(root);
}
void preorder(struct tree *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(struct tree *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("\t%d",p->data);
        inorder(p->right);
    }
}
void postorder(struct tree *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("\t%d",p->data);
    }
}
int main()
{
    int h;
    struct tree *root;
    while(1)
    {
        printf("\nenter 1. for creation of the binary search tree");
        printf("\nenter 2. for preorder traversal");
        printf("\nenter 3. for inorder traversal");
        printf("\nenter 4. for postorder traversal");
        printf("\nenter 5. for exit");
       // printf("\nenter <span id="IL_AD9" class="IL_AD">your choice</span>");
        scanf("%d",&h);
        switch(h)
        {
            case 1:
            root=create();
            break;
            case 2:
            preorder(root);
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            postorder(root);
            break;
           // <span id="IL_AD1" class="IL_AD">case 5</span>:
            exit(0);
            default:
            printf("\nentered a wrong choice");
        }
    }
} 
