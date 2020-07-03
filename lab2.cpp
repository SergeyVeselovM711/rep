#include "lab2.h"
#include <cstring>
#include <semaphore.h>
//
// lab2 code should be located here!
//

#define NUMBER_OF_THREADS 10

// thread identifiers
pthread_t tid[NUMBER_OF_THREADS];
// critical section lock
pthread_mutex_t lock;
// semaphores for sequential threads
sem_t semI, semK, semM, semA, semB, semC, semD, semE, semF, semG, semH, semN;
sem_t semEH, semHE, semHI, semIE;

int err;

unsigned int lab2_thread_graph_id() 
{
    return 16;
}

const char* lab2_unsynchronized_threads()
{
    return "bcef";
}

const char* lab2_sequential_threads()
{
    return "ehi";
}


void *thread_a(void *ptr);

void *thread_b(void *ptr);

void *thread_c(void *ptr);

void *thread_d(void *ptr);

void *thread_e(void *ptr);

void *thread_g(void *ptr);

void *thread_f(void *ptr);

void *thread_h(void *ptr);

void *thread_i(void *ptr);

void *thread_k(void *ptr);


///////////A

void *thread_a(void *ptr)

{

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "a" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semE);
    sem_post(&semB);
    sem_post(&semC);
    sem_post(&semF);

    return ptr;
}

///////////C

void *thread_c(void *ptr)

{
    sem_wait(&semC);
    
    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "c" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semB);
    sem_post(&semF);
    sem_post(&semE);
    sem_post(&semD);
    sem_post(&semG);

    
    return ptr;
}

///////////B

void *thread_b(void *ptr)

{
    sem_wait(&semB);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semG);
    sem_post(&semF);
    sem_post(&semE);
    sem_post(&semD);

    sem_wait(&semB);
    sem_wait(&semB);
    sem_wait(&semB);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "b" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semE);
    sem_post(&semH);
    sem_post(&semG);
    sem_post(&semF);

    return ptr;
}

///////////E

void *thread_e(void *ptr)

{
    sem_wait(&semE);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semG);
    sem_post(&semF);
    sem_post(&semB);
    sem_post(&semD);

    sem_wait(&semE);
    sem_wait(&semE);
    sem_wait(&semE);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semG);
    sem_post(&semF);
    sem_post(&semH);

    sem_wait(&semE);
    sem_wait(&semE);
    sem_wait(&semE);
    sem_wait(&semE);


    for (int i = 0; i < 3; ++i)
    {
        sem_wait(&semHE);
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semEH);
    }

    sem_post(&semI);
    sem_post(&semH);

    sem_wait(&semE);
    sem_wait(&semE);
    sem_wait(&semE);

    for (int i = 0; i < 3; ++i)
    {
        sem_wait(&semIE);
        pthread_mutex_lock(&lock);
        std::cout << "e" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semEH);
    }

    sem_post(&semI);
    sem_post(&semK);


    return ptr;
}

///////////F

void *thread_f(void *ptr)

{
    sem_wait(&semF);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "f" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semG);
    sem_post(&semE);
    sem_post(&semB);
    sem_post(&semD);

    sem_wait(&semF);
    sem_wait(&semF);
    sem_wait(&semF);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "f" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semG);
    sem_post(&semE);
    sem_post(&semH);

    sem_wait(&semF);
    sem_wait(&semF);
    sem_wait(&semF);
    sem_wait(&semF);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "f" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semI);
    sem_post(&semE);
    sem_post(&semH);

    return ptr;
}

///////////D

void *thread_d(void *ptr)

{
    sem_wait(&semD);
    sem_wait(&semD);
    sem_wait(&semD);
    sem_wait(&semD);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "d" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semE);
    sem_post(&semH);
    sem_post(&semG);
    sem_post(&semF);

    return ptr;
}

///////////G

void *thread_g(void *ptr)

{

    sem_wait(&semG);
    sem_wait(&semG);
    sem_wait(&semG);
    sem_wait(&semG);

    for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "g" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semF);
    sem_post(&semE);
    sem_post(&semH);

    sem_wait(&semG);
    sem_wait(&semG);
    sem_wait(&semG);
    sem_wait(&semG);

     for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "g" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    sem_post(&semI);
    sem_post(&semE);
    sem_post(&semH);

    return ptr;
}

///////////H

void *thread_h(void *ptr)

{

    sem_wait(&semH);
    sem_wait(&semH);
    sem_wait(&semH);
    sem_wait(&semH);
    sem_wait(&semH);

    for (int i = 0; i < 3; ++i)
    {
        sem_wait(&semEH);
        pthread_mutex_lock(&lock);
        std::cout << "h" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semHE);
    }

    sem_post(&semE);
    sem_post(&semI);

    sem_wait(&semH);
    sem_wait(&semH);
    sem_wait(&semH);

    for (int i = 0; i < 3; ++i)
    {
        sem_wait(&semEH);
        pthread_mutex_lock(&lock);
        std::cout << "h" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semHI);
    }

    sem_post(&semK);
    sem_post(&semI);

    return ptr;
}

///////////K

void *thread_k(void *ptr)

{

    sem_wait(&semK);
    sem_wait(&semK);
    sem_wait(&semK);

   for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "k" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    return ptr;
}

///////////I

void *thread_i(void *ptr)

{
    sem_wait(&semI);
    sem_wait(&semI);
    sem_wait(&semI);
    sem_wait(&semI);

    for (int i = 0; i < 3; ++i)
    {
        sem_wait(&semHI);
        pthread_mutex_lock(&lock);
        std::cout << "i" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
        sem_post(&semIE);
    }

   sem_post(&semK);

   for (int i = 0; i < 3; ++i)
    {
        pthread_mutex_lock(&lock);
        std::cout << "i" << std::flush;
        pthread_mutex_unlock(&lock);
        computation();
    }

    return ptr;
}



int lab2_init()

{

    if (pthread_mutex_init(&lock, NULL) != 0)
    {

        std::cerr << "Mutex init failed" << std::endl;

        return 1;
    }

    // initialize semaphores

    if (sem_init(&semA, 0, 1) != 0)
    {

        std::cerr << "Semaphore #a init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semB, 0, 0) != 0)
    {

        std::cerr << "Semaphore #b init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semC, 0, 0) != 0)
    {

        std::cerr << "Semaphore #c init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semD, 0, 0) != 0)
    {

        std::cerr << "Semaphore #d init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semE, 0, 0) != 0)
    {

        std::cerr << "Semaphore #e init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semF, 0, 0) != 0)
    {

        std::cerr << "Semaphore #f init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semG, 0, 0) != 0)
    {

        std::cerr << "Semaphore #g init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semH, 0, 0) != 0)
    {

        std::cerr << "Semaphore #h init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semN, 0, 0) != 0)
    {

        std::cerr << "Semaphore #n init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semK, 0, 0) != 0)
    {

        std::cerr << "Semaphore #k init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semM, 0, 0) != 0)
    {

        return 1;
    }

    if (sem_init(&semI, 0, 0) != 0)
    {

        std::cerr << "Semaphore #i init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semHE, 0, 1) != 0)
    {

        std::cerr << "Semaphore #a init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semIE, 0, 1) != 0)
    {

        std::cerr << "Semaphore #a init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semEH, 0, 0) != 0)
    {

        std::cerr << "Semaphore #a init failed" << std::endl;

        return 1;
    }

    if (sem_init(&semHI, 0, 0) != 0)
    {

        std::cerr << "Semaphore #a init failed" << std::endl;

        return 1;
    }


    ///////////////////////////////

    //create

    err = pthread_create(&tid[0], NULL, thread_a, NULL);

    if (err != 0)

        std::cerr << "Can't create thread A. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[1], NULL, thread_c, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[2], NULL, thread_b, NULL);

    if (err != 0)

        std::cerr << "Can't create thread b. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[3], NULL, thread_d, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[4], NULL, thread_e, NULL);

    if (err != 0)

        std::cerr << "Can't create thread e. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[5], NULL, thread_f, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[6], NULL, thread_g, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[7], NULL, thread_h, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[8], NULL, thread_k, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;

    err = pthread_create(&tid[9], NULL, thread_i, NULL);

    if (err != 0)

        std::cerr << "Can't create thread C. Error: " << strerror(err) << std::endl;


    pthread_join(tid[8], NULL);

    pthread_join(tid[9], NULL);

    // pthread_join(tid[5], NULL);

    // sem_post(&semG);

    // for (int i = 0; i < 11; ++i)
    // {

    //     pthread_join(tid[i], NULL);
    // }

    // free resources

    pthread_mutex_destroy(&lock);

    // destroy semaphores

    sem_destroy(&semM);

    sem_destroy(&semI);

    sem_destroy(&semK);

    sem_destroy(&semA);

    sem_destroy(&semB);

    sem_destroy(&semC);

    sem_destroy(&semD);

    sem_destroy(&semE);

    sem_destroy(&semF);

    sem_destroy(&semG);

    sem_destroy(&semH);

    sem_destroy(&semEH);

    sem_destroy(&semHE);

    sem_destroy(&semHI);

    sem_destroy(&semIE);

    std::cout << std::endl;

    return 0;
}