#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    mode_t m = umask(027); // 027 -> permiso 750
	int file = open("ej6.txt", O_CREAT | O_RDONLY, 0777);
	return 0;
}
