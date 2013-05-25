#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proto.h"
#include <sys/stat.h>
struct Node *head;
struct Node *tail;
struct Node* extract_dir(char* path)
{
        head=tail=NULL;
	int a = 0;
        char* currentpath=NULL;
        currentpath=malloc(sizeof(char)*300);
        puts("extracting.....");
        if(path[a]=='/')
        {
         struct Node *node;
         node=(struct Node*)malloc(sizeof(struct Node));
         node->data="/";
         node->path="/";
         currentpath[a]='/';
         head=node;
         tail=node;
         head->next=NULL;
         tail->next=NULL;
         a++;
        }
	while(path[a]!='\0')
	{
		struct Node *node;
		node = (struct Node*)malloc(sizeof(struct Node));
                node->data=malloc(sizeof(char)*30);
                node->path=malloc(sizeof(char)*100);                
		int i=0;
		while(path[a]!='/')
		{
			*((node->data)+i)=*(path+a);
                        *(currentpath+a)=*(path+a);
                        i++;
                        a++;
		}
                *(node->data+i)='\0';
                *(currentpath+a)=*(path+a);
                *(currentpath+a+1)='\0';
                strcpy(node->path,currentpath);
                a++;
		node->prev = NULL;
		node->next = NULL;
		if(head==NULL)
		{
			head = tail = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}
}

struct Node* deleteq()
{
	struct Node *p = head;
	if(p->next == NULL)
	{
		head = NULL;
                tail=NULL;
	}
	else
	{
		head = p->next;
		p->prev = NULL;
                p->next = NULL;
	}
        
        return p;
}
void insert(struct file** root1,char* path, char* file_name)
{
        
        struct file** temp1 = root1;
        struct file* temp = *temp1;
	extract_dir(path);
        
        struct file* prev=NULL;
	while(head!=NULL)
	{
 
                struct Node* q = deleteq();
                if((temp)==NULL)
                {
                  struct file* node;
                  node=malloc(sizeof(struct file));
                  node->filename=q->data;
                  node->path=q->path;
                  node->left=NULL;
                  node->right=NULL;
                  struct stat* sb;
                  sb = malloc(sizeof(struct stat));
                  lstat(node->path,sb);
                  node->atime=sb->st_atime;
	   	  node->mtime=sb->st_mtime;
		  node->ctime=sb->st_ctime;
                  node->isdir=S_ISDIR(sb->st_mode);
                  node->isfile=S_ISREG(sb->st_mode);
                  node->comp=0;
                  free(q);
                  q=NULL;
                  if(prev!=NULL)
                     prev->left=node;
                  if((*temp1)==NULL)
                     (*temp1)=node;
                  (temp)=node;
                  prev=(temp);
                  (temp)=(temp)->left;
                  continue;
                }
		while((temp)!=NULL&&strcmp((temp)->filename,(q)->data)!=0)
                {
                  prev=(temp);
                  (temp) = (temp)->right;
		}
	        if((temp)!=NULL&&strcmp((temp)->filename,(q)->data)==0)
                {
                 
                    prev=(temp);
                    (temp)=(temp)->left;
                 
                    free(q);
                    q=NULL;
                    continue;
                }
                if((temp)==NULL)
                {
                  struct file* node;
                  node=malloc(sizeof(struct file)); 
                  node->filename=q->data;
                  node->path=q->path;
                  node->left=NULL;
                  node->right=NULL;
                  struct stat* sb;
                  sb = malloc(sizeof(struct stat));
                  lstat(node->path,sb);
                  node->atime=sb->st_atime;
                  node->mtime=sb->st_mtime;
                  node->ctime=sb->st_ctime;
                  node->isdir=S_ISDIR(sb->st_mode);
                  node->isfile=S_ISREG(sb->st_mode);
                  node->comp=0;
                  free(q);
                  q=NULL;
                  (temp)=node;
                  prev->right=(temp);
		  (temp)=(temp)->left;
              }

	}
        
}


		
