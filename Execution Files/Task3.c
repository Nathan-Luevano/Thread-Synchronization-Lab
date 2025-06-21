#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 500000000
long long sum = 0;


void* counting_function(void *arg)
{  
    int offset = *(int *) arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
        sum += offset;
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t id1;
    int offset1 = 1;
    pthread_create(&id1, NULL, counting_function, &offset1);

    pthread_join(id1, NULL);

    printf("Sum = %lld\n", sum);
    return 0;
}
