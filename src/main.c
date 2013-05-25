#include <stdio.h>
#include "proto.h"
int main()
{
  struct dirent* ep;
  FILE *fp;
  fp=fopen("/home/vidhisha/FileSystemConsistency/merge/tree.txt","w");
  fputs("",fp);
  fclose(fp);
  list("/home/vidhisha/hello/");
  puts("\nORIGINAL TREE:\n");
  display(root);
  duplicate(&dup_root,root);
  puts("\nDUPLICATE TREE:\n");
  display(dup_root);
  compare(root,&dup_root);
  int choice=0;
  int run=1;
  while(run)
  {
   puts("1.traverse original tree \n 2.compare\n3.Exit");
   puts("Enter your choice");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1: free_the_root(&root);
            root=NULL;
	    list("/home/vidhisha/hello/");
            puts("Original tree");
            display(root);
            break;
    case 2: initialise(&dup_root);
            compare(root,&dup_root);
            puts("duplicate tree");
            display(dup_root);
            break;
    case 3: run=0;
            break;
   }
  }
}
