exec: unlink_delete_me
	./unlink_delete_me

unlink_delete_me:
	gcc -o unlink_delete_me unlink_delete_me.c

clean:
	touch delete.me
	echo I will miss you > delete.me

