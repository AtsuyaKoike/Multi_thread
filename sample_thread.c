#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void func( int x );

int main( )
{
	pthread_t t1;
	pthread_t t2;
	pthread_create( &t1, NULL, (void*)func, (void*)1 );
	pthread_create( &t2, NULL, (void*)func, (void*)2 );
	printf("main()\n");
	pthread_join( t1, NULL );
	pthread_join( t2, NULL );
	return 0;
}

void func( int x )
{
	int i;
	for( i = 0; i < 10; i++ )
	{
		printf("func(%d): %d\n", x, i );
		usleep( 100000 );
	}
}
