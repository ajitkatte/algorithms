#include<stdio.h>
#include<stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *right;
 struct binary_search_tree *left;
}tree;

void insert(tree *, tree *);
tree *createNewNode();
void preorder(tree *);
void postorder(tree *);
void inorder(tree *);


int main()
{
  int choice;
  tree *newNode, *root, *temp, *parent;
  root = NULL;
  printf("\nBinary search program : ");
  do
  {
    printf("\n1.Create");
    printf("\n2.Traverse");
    printf("\n3.Exit");
  
  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
   case 1:
          newNode = createNewNode();
          printf("\nEnter data to be inserted");
          scanf("%d",&newNode->data);

          if(root == NULL)
             root = newNode;
          else
             insert(root, newNode);
          break;
  case 2:
         if(root == NULL)
           printf("\nTree is empty. Please create a new one.");
         else
           {
             printf("\n Inorder: ");
             inorder(root);
             printf("\n PreOrder: ");
             preorder(root);
             printf("\n PostOrder: ");
             postorder(root);            
           }
         break;
  }
}while(choice != 3);
return 0;
}


tree* createNewNode()
{
  tree *newNode;
  newNode = (tree *) malloc(sizeof(tree));
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
}


void insert(tree *root,tree *newNode)
{
  if(root == NULL)
  {
   root = newNode;
  }
  if(newNode->data <root->data)
  {
   if(root->left == NULL)
      root->left = newNode;
   else
      insert(root->left, newNode);
  }

  if(newNode->data > root->data)
  {
   if(root->right == NULL)
      root->right = newNode;
   else 
      insert(root->right, newNode);
  }
}

void preorder(tree *temp)
{
  if(temp != NULL)
  {
    printf("%d->", temp->data);
    preorder(temp->left);
    preorder(temp->right);
  }
}

void postorder(tree *temp)
{
  if(temp != NULL)
  { 
   postorder(temp->left);
   postorder(temp->right);
   printf("%d->", temp->data);
  }
}


void inorder(tree *temp)
{
  if(temp != NULL)
  {
    inorder(temp->left);
    printf("%d->",temp->data);
    inorder(temp->right);
  }
}
