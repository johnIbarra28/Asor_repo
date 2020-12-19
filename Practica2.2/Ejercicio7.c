#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    mode_t a = umask(0132); // mascara 0132 para permiso 645
    int df = open("eje7.txt", O_CREAT, 0777);
    mode_t l = umask(a);
	printf("Last: %i\n", l);
    return 1;
}
