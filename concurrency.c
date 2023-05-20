// Nour A Sharaky - 202000149
// KH5068CEM Platforms and Operating Systems CW1
// Thread Concurrency using mutex locks

// This code creates 5 threads that each increment a shared counter 1 million times
// The counter is protected by a mutex lock to ensure that only one thread can access it at a time

// ____________________________________________________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// ____________________________________________________________________________________

#define NUM_THREADS 5                       // define the number of threads to create
#define MAX_COUNT 1000000                   // define the maximum number of times to increment the counter

int counter = 0;                            // variable stores the shared counter
pthread_mutex_t mutex;                      // mutex lock to protect the counter from concurrent access

// ____________________________________________________________________________________

// This function is called by each thread to increment the counter

void* increment_counter(void* thread_id) {
    long tid = (long)thread_id;

    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex);         // Acquire the lock to enter the critical section
        counter++;                          // Increment the shared counter 
        pthread_mutex_unlock(&mutex);       // Release the lock to exit the critical section
    }

    // Print a message to indicate that the thread has finished
    printf("Thread %ld finished\n", tid);

    pthread_exit(NULL);
}

// ____________________________________________________________________________________

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Initialize the mutex lock
    pthread_mutex_init(&mutex, NULL);        

    // Creates 5 threads
    for (t = 0; t < NUM_THREADS; t++) {
        // Create a thread and pass in the thread ID
        rc = pthread_create(&threads[t], NULL, increment_counter, (void*)t);  

        // error checking
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);         
    }

    // Print the final value of the counter
    printf("\nCounter value: %d\n\n", counter);

    // Destroy the mutex lock
    pthread_mutex_destroy(&mutex);              

    pthread_exit(NULL);
}

// ____________________________________________________________________________________