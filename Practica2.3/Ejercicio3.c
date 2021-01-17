#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char **argv) {
	if (argc != 2) {
    printf("ERROR: DEBE INTRODUCIR PID\n");
    return -1;
  }

  int pid = atoi(argv[0]);
  int scheduler = sched_getscheduler(pid);


  //Planificador
  switch (scheduler) {
    case SCHED_OTHER:
      printf("Planificador: OTHER\n");
    break;
    case SCHED_FIFO:
      printf("Planificador: FIFO\n");
    break;
    case SCHED_RR:
      printf("Planificador: RR\n");
    break;
    default:
      printf("Planificador: ERROR\n");
    break;
  }
  //Obtenemos la prioridad
  struct sched_param prio;
  sched_getparam(pid,&prio);
  printf("PRIORIDAD: %i\n", prio.sched_priority);

  //Obtenemos los rangos maximo y minimo
  int maximo = sched_get_priority_max(scheduler);
  int minimo = sched_get_priority_min(scheduler);
  printf("MAXIMO: %i - MINIMO: %i\n", maximo, minimo);

}
