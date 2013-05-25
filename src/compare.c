#include "proto.h"
#include <stdio.h>
#include <stdlib.h>
struct file** parent;
int flag=0;
void compare(struct file* original, struct file** duplicate)
{
 if(original==NULL)
 {
 
   return;
 }
 struct file* temp=original;
 struct file** first = duplicate;
 while(temp!=NULL)
 {
  
  struct file** temp1 = first;
  struct file** prev = NULL;
  while((*temp1)!=NULL)
  {
   if(strcmp(temp->path,(*temp1)->path)==0)
   {
    (*temp1)->comp=1;
    if(temp->isdir==1)
    {
     {
      parent=temp1;
      compare(temp->left,&(*temp1)->left);
      break;
     }
    }
    else
    {
     if(temp->mtime!=(*temp1)->mtime)
     {
      puts("file modified");
      (*temp1)->mtime=temp->mtime;
     }
     break;
    }
       
   }
   else
   {
    
    prev=temp1;
    temp1=&((*temp1)->right);
    if((*temp1)==NULL)
      flag=1;
   }
  }
  if((*temp1)==NULL)
  {
      struct file* node;
   node= malloc(sizeof(struct file));
   node->filename=temp->filename;
   node->path=temp->path;
   node->atime=temp->atime;
   node->mtime=temp->mtime;
   node->ctime=temp->ctime;
   node->isdir=temp->isdir;
   node->isfile=temp->isfile;
   node->left=NULL;
   node->right=NULL;
   node->comp=1;
   if(flag)
   {
     (*prev)->right=node;
     flag=0;
     compare(temp->left,&(*temp1)->left);
   }
   else
   {
      (*parent)->left=node;
      compare(temp->left,&(*temp1)->left);
   }   
  }
  temp=temp->right;
 }
 struct file** temp2 = first;
 struct file** prev=NULL;
 while((*temp2)!=NULL)
 {
  if((*temp2)->comp==0)
  {
   puts((*temp2)->path);
   (*prev)->right=(*temp2)->right;
   free_the_root(temp2);
   temp2=&(*prev)->right;
   continue;
  }
  prev=temp2;
  temp2=&(*temp2)->right;
  
 }
 
 
}
  
 

	
