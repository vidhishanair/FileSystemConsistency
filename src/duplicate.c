#include <stdio.h>
#include "proto.h"
#include<stdlib.h>
void duplicate(struct file** d_root,struct file* o_root)
{
 if((o_root)==NULL)
    return;
 insert(d_root,o_root->path,o_root->filename);
 duplicate(d_root,o_root->left);
 duplicate(d_root,o_root->right);
}
void free_the_root(struct file** temp)
{
 if((*temp)==NULL)
   return;
 free_the_root(&((*temp)->left));
 free_the_root(&((*temp)->right));
 free(*temp);
 (*temp)=NULL;
}
void initialise(struct file** temp)
{
 if((*temp)==NULL)
   return;
 (*temp)->comp=0;
 initialise(&(*temp)->left);
 initialise(&(*temp)->right);
}
