#include <sys/types.h>
struct Node
{
	struct Node* next;
	char* data;
        char* path;
	struct Node* prev;
};
struct file
{
  struct file* left;
  struct file* right;
  char* path;
  char* filename;
  time_t atime;
  time_t mtime;
  time_t ctime;
  int isdir;
  int isfile;
  int comp;
};
struct file* root;
struct file* dup_root;
void list(char*);
void insert(struct file**,char*,char*);
void display();
void duplicate(struct file**,struct file*);
void compare(struct file*,struct file**);
void free_the_root(struct file**);
void initialise(struct file**);
