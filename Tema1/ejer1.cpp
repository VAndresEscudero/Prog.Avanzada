#include <stdio.h>
#include <time.h>

int f (int i) 
{
	return 0;
}

int main (int argc, char *argv[]) 
{
	
	int segundos, nano_segundos;
	struct timespec request_start, request_end;

	clock_gettime(CLOCK_REALTIME, &request_start);

	for (int i = 0; i <= 1000; i++)
		f(i);
	
	clock_gettime(CLOCK_REALTIME, &request_end);
	
	segundos = (request_end.tv_sec - request_start.tv_sec);
	nano_segundos = ( request_end.tv_nsec - request_start.tv_nsec );

	printf ("%i segundos\n", segundos);
	printf ("%i nano segundos\n", nano_segundos);

	return 0;	
}
