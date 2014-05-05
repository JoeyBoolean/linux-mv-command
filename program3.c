/*
Joey Bachand
jjbachan
Program 3
12/1/13
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 1024

void changeDir(char *old, char *new);
void move(char *old, char *new);
void usage(int error, char *old, char *new);

int main(int argc, char *argv[])
{
    /*Declarations*/
    char *old_file, *new_file;
    struct stat new_sb, old_sb;

    old_file = argv[1];
    new_file = argv[2];

    /*Error Handling*/
    if(argc == 1)
      usage(0, "", "");
    if(argc == 2)
      usage(1, old_file, "");

    if(stat(old_file, &old_sb) == -1)
      usage(errno, old_file, new_file);

    if(stat(new_file, &new_sb)==-1)
      if(errno != ENOENT) errExit("stat");

    if(S_ISDIR(new_sb.st_mode))
      changeDir(old_file, new_file);

    else
      move(old_file, new_file);

    exit(EXIT_SUCCESS);
}

/*Calls the rename function and handles errors.*/
void move(char *old, char *new)
{
  if (rename( old, new) == -1)
  {
    if(errno == EISDIR || errno == ENOTEMPTY)
      changeDir(old, new);
    
    else
      usage(errno, old, new);
  }
}

/*Changes destination to be within the directory that 
is the target of the mv command.*/
void changeDir(char *old, char *new)
{
  char buffer[BUF_SIZE];
  char *slash;
  int len = strlen(old);
  slash = strrchr(old, '/');

  if((slash - old) == --len)
  {
    old[len] = 0;
    slash = strrchr(old, '/');
  }

  if(slash == NULL)
    slash = old;
  else
    slash++;

  sprintf(buffer, "%s/%s", new, slash);
  move(old, buffer);
}

/*Error Messages*/
void usage(int error, char *old, char *new)
{
  if(error == ENOTDIR)
    fprintf(stderr,"my_mv: cannot overwrite non-directory `%s' with directory `%s'\n", new, old);
  if(error == ENOENT)
    fprintf(stderr,"my_mv: cannot stat `%s': No such file or directory\n", old);
  if(error == 0)
    fprintf(stderr,"my_mv: missing file operand\nTry `mv --help' for more information.\n");
  if(error == 1)
    fprintf(stderr,"my_mv: missing destination file operand after `%s'\n"
      "Try `mv --help' for more information.\n", old);
  if(error == EINVAL)
    fprintf(stderr, "my_mv: cannot move `%s' to a subdirectory of itself, `%s'\n",old, new );
  exit(1);
}