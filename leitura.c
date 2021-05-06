#include <sys/stat.h>
#include <stdio.h>

int main(){
	struct stat s;
	char* f = "delete.me";

	stat(f, &s);
	if (s.st_mode & S_IWUSR)
		puts("O arquivo delete.me está com permissão de escrita para o dono");
	else
		puts("O arquivo delete.me não está com permissão de escrita para o dono");
}
