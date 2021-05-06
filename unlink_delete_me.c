#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char* file = "delete.me";
	int res = unlink(file);
	if (res == -1){
		perror("SO2 ");
		exit(1);
	}
	
}
