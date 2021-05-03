#include <unistd.h>
int main(){
	char* file = "delete.me";
	unlink(file);
}
