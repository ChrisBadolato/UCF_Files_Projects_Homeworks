/*
 * This code is provided by M. McAlpin and can be freely used for solving
 * problems in COP3502 (aka CS1).
 *
 * In the event you need to use it for some other application or course
 * PLEASE confirm with the appropriate parties. At the minimum, if using
 * this code for another course, please check with the author
 * at the following email address:
 *          michael.mcalpin@ucf.edu
 *
 */
/* Recap left & right rotations (simple case)
T1, T2 and T3 are subtrees of the tree rooted with y (on left side)
or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the following order
      keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
*/

#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct node
{
    float key;
    struct node *left;
    struct node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(float key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

/*
 * RECAP Balance is based on Height
 *     Hn = Hl - Hr
 * so
 *    positive => LEFT HEAVY
 *    negative => RIGHT HEAVY
 */
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, float key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes UNBALANCED, then there are 4 cases

    /* CASE # 1 => LEFT-LEFT aka left?
       T1, T2, T3 and T4 are subtrees.
         z                                      y
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
     */
    // Left Left Case in code
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    /* Case #2 => RIGHT-RIGHT aka right?

       z                                y
      /  \                            /   \
     T1   y     Left Rotate(z)       z      x
         / \   - - - - - - - -->    / \    / \
	T2  x                     T1  T2 T3  T4
       / \
     T3  T4

     */
    // Right Right Case in code
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);


    /* CASE # 3 => LEFT-RIGHT aka left-right?
     z                               z                           x
    / \                            /   \                        /  \
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2

    */
    // Left Right Case in code
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    /* CASE #4 = RIGHT-LEFT aka right-left?
        z                            z                            x
       / \                          / \                          /  \
      T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
      / \   - - - - - - - - ->     /  \      - - - - - - - ->  / \    /	\
    x   T4                       T2    y                      T1  T2  T3  T4
   / \                                /  \
 T2   T3                             T3   T4
     */
    // Right Left Case in code
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
      printf("%.4f/%1d ", root->key, root->height);
      preOrder(root->left);
      preOrder(root->right);
    }
}
void inOrder(struct node *root)
{
    if(root != NULL)
    {
      inOrder(root->left);
      printf("%.4f/%1d ", root->key, root->height);
      inOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if(root != NULL)
    {
      postOrder(root->left);
      postOrder(root->right);
      printf("%.4f/%1d ", root->key, root->height);
    }
}
void reverseOrder(struct node *root)
{
    if(root != NULL)
    {
        reverseOrder(root->right);
        printf("%.4f/%1d ", root->key, root->height);
        reverseOrder(root->left);
    }
}

/* Driver program to test above functions*/
int main(int argc, char *argv[])
{

    struct node *root = NULL;
    char eachLine[50];
    float number;
    char* order = argv[1];
    while(fgets(eachLine, sizeof(eachLine), stdin) != NULL){
        number = atof(eachLine);
        root = insert(root, number);
    }

    if(order[0] == 'd'){
        printf("Reverse order\n");
        reverseOrder(root);
        printf("\n");
    }

    if(order[0] == 'a'){
        printf("In order\n");
        inOrder(root);
        printf("\n");
    }
    else {
        return 0;
    }



 /* Constructing tree given in the above figure */

    root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \    \
       10  25   50
  */
/*
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
  printf("\n");

  printf("In order traversal of the constructed AVL tree is \n");
  inOrder(root);
  printf("\n");

  printf("Post order traversal of the constructed AVL tree is \n");
  postOrder(root);
  printf("\n");

  /*
   * BH? (Big Hint)
   *   To print an AVL Tree in reverse or descending order is
   *   really the opposite of printing it "inOrder".
   */


  return 0;
}
