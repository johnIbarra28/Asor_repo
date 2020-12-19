#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char **argv){
    if(argc < 2){
        printf("Error: especificar ruta delarchivo y parametros.\n");
        return -1;
    }
    
    struct stat buff;

    int statInt = stat(argv[1], &buff);
    
    if(statInt == -1){
        printf("Error: No existe el directorio.\n");
        return -1;
    }

    printf("Major: %li\n", (long)major(buff.st_dev));
    printf("Minor: %li\n", (long)minor(buff.st_dev));
    printf("Inodo: %li\n", buff.st_ino);
    if(S_ISREG(buff.st_mode)){
        printf("Tipo de fichero: Fichero regular.\n");
    }
    else if(S_ISDIR(buff.st_mode)){
        printf("Tipo de fichero: Directorio.\n");
    }
    else{
        printf("Otro tipo distinto de fichero o directorio.\n");
    }

	time_t t = buff.st_atime;
	struct tm *tm1= localtime(&t);
	printf("Tiempo de ultimo acceso (A): %d:%d\n", tm1->tm_hour, tm1->tm_min);


	time_t t2 = buff.st_mtime;
	struct tm *tm2= localtime(&t2);
	printf("Fecha ultima modificacion de archivo (M): %d:%d\n", tm2->tm_hour, tm2->tm_min);


	time_t t3 = buff.st_ctime;
	struct tm *tm3= localtime(&t3);
	printf("Tiempo de ultima modificacion de permisos (C): %d:%d\n", tm3->tm_hour, tm3->tm_min);

    return 1;
}
