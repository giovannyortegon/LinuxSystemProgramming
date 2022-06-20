#include<stdio.h>
#include<pthread.h>

void * add(void * arg);
long long int i = 0;
pthread_mutex_t i_mutex;

int main() {
    pthread_attr_t threaddattr;
    pthread_attr_init(&threaddattr);

    pthread_t tid_add1, tid_add2, tid_add3, tid_add4, tid_add5;

    if ((pthread_mutex_init(&i_mutex, NULL)) != 0) {
        fprintf(stderr, "Could'nt initialize mutex\n");
        return (1);
    }

    pthread_create(&tid_add1, &threaddattr, add, NULL);
    pthread_create(&tid_add2, &threaddattr, add, NULL);
    pthread_create(&tid_add3, &threaddattr, add, NULL);
    pthread_create(&tid_add4, &threaddattr, add, NULL);
    pthread_create(&tid_add5, &threaddattr, add, NULL);

    pthread_join(tid_add1, NULL);
    pthread_join(tid_add2, NULL);
    pthread_join(tid_add3, NULL);
    pthread_join(tid_add4, NULL);
    pthread_join(tid_add5, NULL);

    printf("Sum is %lld\n", i);

    if ((pthread_mutex_destroy(&i_mutex)) != 0) {
        fprintf(stderr, "Could'nt destroy mutex\n");
        return (1);
    }

    return (0);
}

void * add(void * arg) {
    for (long long int j = 1; j <= 1000000000; j++) {
        pthread_mutex_lock(&i_mutex);
        i += 1;
        pthread_mutex_unlock(&i_mutex);
    }

    return (NULL);
}