#include<stdio.h>
#include<stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *right;
 struct binary_search_tree *left;
}tree;

void insert(tree *, tree *);
tree *create_new_node();
void preorder(tree *);
void postorder(tree *);
void inorder(tree *);


int main()
{
  int choice;
  tree *new_node, *root;
  root = NULL;
  printf("\nBinary search tree: ");
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
          new_node = create_new_node();
          printf("\nEnter data to be inserted: ");
          scanf("%d",&new_node->data);

          if(root == NULL)
             root = new_node;
          else
             insert(root, new_node);
          break;
  case 2:
         if(root == NULL)
           printf("\nThe tree is empty. Please create a new one.");
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


tree* create_new_node()
{
  tree *new_node;
  new_node = (tree *) malloc(sizeof(tree));
  new_node -> left = NULL;
  new_node -> right = NULL;
  return new_node;
}


void insert(tree *root,tree *new_node)
{
  if(root == NULL)
  {
   root = new_node;
  }
  if(new_node->data <root->data)
  {
   if(root->left == NULL)
      root->left = new_node;
   else
      insert(root->left, new_node);
  }

  if(new_node->data > root->data)
  {
   if(root->right == NULL)
      root->right = new_node;
   else 
      insert(root->right, new_node);
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
