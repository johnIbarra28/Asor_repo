#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {

  printf("PID: %i\n", getpid());
  printf("PPID: %i\n", getppid());
  printf("PPID: %i\n", getsid(getpid()));
  struct rlimit limit;

  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    perror("ERROR en limite");
    return -1;
  }

  printf("LIMITE: %li\n", limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("CWD: %s\n", path);
  free (path);

  return 0;
}
