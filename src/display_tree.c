#include <stdio.h>
#include "proto.h"
void display(struct file* root)
{
 if(root==NULL)
 {
   return;
 }
 puts(root->path);
 display(root->left);
 display(root->right);
}
