#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
extern char **environ;

static int mm;

struct s {
int  base;
char listener;
};
char s[0];
/*int main()
{
struct s *x;
struct s y;
size_t	ix=0;
struct s *m = &y;
printf("x=%p m=%p\n", x, m);
ix= (long)offsetof(struct s, base);
x = (struct s*)((char *)m - ix );
printf("x = %p m=%p %s\n", x, m,s[1]);
return 0;
}*/

int main (int argc, char **argv, char **envp)
{

char **var = envp;
printf("%p %p %d\n",envp,environ,mm);
while (*var)
printf ("%s \n",*var++);
return 0;
}


