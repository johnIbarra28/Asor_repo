#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>


void printAtributos(char *type){
  printf("[%s]PID: %i\n", type,getpid());
  printf("[%s]PPID: %i\n", type, getppid());
  printf("[%s]PPID: %i\n", type, getsid(getpid()));
  struct rlimit limit;
  if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
    perror("ERROR EN LIMITES");
  }
  printf("[%s]LIMITE: %li\n", type, limit.rlim_max);

  char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
  printf("[%s]CWD: %s\n", type, path);
  free (path);
}

int main() {

  pid_t pid = fork();

  switch (pid) {
    case -1:
      perror("fork");
      exit(-1);
    break;
    case 0:;
      pid_t mi_sid = setsid();
      char *ncwd= chdir("/tmp");

      printf("[Hijo] Proceso %i (Padre: %i)\n",getpid(),getppid());
      printAtributos("Hijo");
      break;
    default:
        printf("[Padre] Proceso %i (Padre: %i)\n",getpid(),getppid());
        printAtributos("Padre");
        break;
  }

  return 0;
}
