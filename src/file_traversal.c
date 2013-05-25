#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "proto.h"
void list(char *d_name)
{ 
  puts("hey hi");
  FILE *fp;
  fp=fopen("/home/vidhisha/FileSystemConsistency/merge/tree.txt","a");
  puts("opened");
  DIR *dp;
  dp=opendir(d_name);
  struct dirent *ep;
  struct stat* sb;
  puts("hello");
  sb=malloc(sizeof(struct stat));
  lstat(d_name,sb);
  if(dp!=NULL)
  {
    while(ep=readdir(dp))
    {
     struct dirent* d;
     if(strcmp(ep->d_name,".")!=0&&strcmp(ep->d_name,"..")!=0&&S_ISFIFO(sb->st_mode)!=1&&strcmp(d_name,"/dev/fd/")!=0&&strcmp(d_name,"/usr/bin/X11/")!=0&&strcmp(d_name,"/proc/")!=0&&strcmp(d_name,"/sys/")!=0&&strcmp(d_name,"/lib/recovery-mode/recovery-mode/")!=0&&strcmp(d_name,"/usr/share/recovery-mode/recovery-mode/")!=0&&S_ISLNK(sb->st_mode)!=1)
     {
	char * dn=malloc(300*sizeof(char));//=ds;
	strcpy(dn,d_name);
	dn= strcat(dn,ep->d_name);
	dn = strcat(dn,"/");
	puts(dn);
        insert(&root,dn,d_name);
        fputs(dn,fp);
        fputs("\n",fp);
        fclose(fp);
        list(dn);
        free(dn);
     }
     else
     {
       puts(ep->d_name);
       fputs(ep->d_name,fp);
       fputs("\n",fp);
     }
    }
    (void)closedir(dp);
  }
}
