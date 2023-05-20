<hr>

NOUR SHARAKY - 2020000149 - NS00149@tkh.edu.eg

Coventry University - The Knowledge Hub Universities branch - Bsc of Ethical Hacking and Cybersecurity - Level 5.

KH5068CEM Platforms and Operating Systems - Coursework 2

<hr>

# Thread Concurrency using Mutex Locks

This code demonstrates how to handle concurrent access to a shared resource using mutex locks in C programming language. In this example, we have a shared counter variable that multiple threads will try to increment simultaneously. The purpose of using mutex locks is to ensure that only one thread can access the counter at a time, preventing data corruption and ensuring consistent results.

## How it works

1. We define the number of threads to create (`NUM_THREADS`) and the maximum number of times to increment the counter (`MAX_COUNT`).
2. We have a global variable `counter` that represents the shared counter.
3. We create a mutex lock `mutex` to protect the counter from concurrent access.
4. Each thread runs the `increment_counter` function, which is responsible for incrementing the shared counter.
5. Inside the `increment_counter` function, the thread acquires the lock using `pthread_mutex_lock` to enter the critical section.
6. It increments the counter by one and then releases the lock using `pthread_mutex_unlock` to exit the critical section.
7. This process is repeated `MAX_COUNT` times for each thread.
8. Once a thread finishes its task, it prints a message indicating that it has finished.
9. The `main` function creates the threads and waits for them to finish using `pthread_create` and `pthread_join` respectively.
10. After all threads have finished, the final value of the counter is printed.
11. Finally, the mutex lock is destroyed using `pthread_mutex_destroy`.

## Usage

To run this code, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/NourSharaky/KH5068CEM_Platforms_and_Operating_Systems_CW2.git
   ```

2. Compile the code:

   ```bash
   gcc -o concurrency concurrency.c -pthread
   ```

3. Execute the program:

   ```bash
   ./concurrency
   ```
