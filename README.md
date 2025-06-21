# Thread Synchronization Lab

A comprehensive exploration of thread synchronization concepts in C using POSIX threads (pthreads). This repository contains a series of progressively complex programs that demonstrate threading fundamentals, race conditions, and synchronization mechanisms.

## Overview

This collection of C programs illustrates the evolution from single-threaded to multi-threaded programming, highlighting common pitfalls and their solutions. Each task builds upon the previous one, introducing new concepts and demonstrating both correct and incorrect approaches to concurrent programming.

## Programs Included

### Task1.c - Single Thread Counting Program
Basic counting program that increments a global sum variable 500,000,000 times using a single thread.

### Task2.c - Doubling the Length of a Single Thread Program
Extends Task1 by adding a second function call that decrements the sum, demonstrating sequential execution.

### Task3.c - Counting Up With a Thread
Introduces pthread library usage by converting the counting function to run in a separate thread.

### Task4.c - Counting Up and Down With a Thread
Creates two threads that run sequentially - one increments and one decrements the global sum.

### Task5.c - Running Two Coinciding Threads
Demonstrates a race condition by running two threads concurrently without proper synchronization.

### Task6.c - Solving the Race Condition
Fixes the race condition from Task5 by implementing mutex locks around the critical section.

### Task7.c - Modified Loop Count with Shared Variable Issue
Reduces the loop count to 20,000,000 and introduces a subtle bug by reusing the same offset variable for both threads.

### Task8.c - Race Condition Demonstration
Further reduces the loop count to 2,000,000 to make the race condition more apparent and easier to observe.

### Task9.c - Fixing the New Race Condition
Corrects the variable sharing issue from Tasks 7 and 8 by using separate offset variables for each thread.

### Task10.c - Minimal Synchronization Requirements
Demonstrates a scenario with only 100 iterations where race conditions are less likely to occur due to the minimal execution time.

## Key Concepts Demonstrated

- **Thread Creation and Management**: Using `pthread_create()` and `pthread_join()`
- **Race Conditions**: How concurrent access to shared variables can lead to unpredictable results
- **Mutex Synchronization**: Using `pthread_mutex_lock()` and `pthread_mutex_unlock()` to protect critical sections
- **Critical Sections**: Identifying code segments that require exclusive access
- **Thread Timing Issues**: How thread execution order affects program outcomes

## Compilation and Execution

To compile any of the programs:

```bash
gcc -pthread TaskX.c -o TaskX
```

To run a program:

```bash
./TaskX
```

To measure execution time:

```bash
time ./TaskX
```

## Expected Outputs

- **Tasks 1, 3**: Sum = 500000000
- **Tasks 2, 4, 6, 9, 10**: Sum = 0 (correct synchronization)
- **Task 5**: Unpredictable result due to race condition
- **Tasks 7, 8**: May show incorrect results due to variable sharing issues

## Requirements

- GCC compiler with pthread support
- POSIX-compliant system (Linux, macOS, Unix)
- pthread library

## Learning Objectives

This repository serves as a practical guide for understanding:

1. The transition from sequential to concurrent programming
2. Common threading mistakes and their consequences
3. Proper synchronization techniques
4. Performance implications of different synchronization approaches
5. When synchronization is and isn't necessary

## Notes

- The programs use a global variable `sum` to demonstrate shared memory access
- Mutex locks ensure thread safety but may impact performance
- Loop counts vary across tasks to highlight different aspects of concurrent execution
- Some tasks intentionally contain bugs to demonstrate problematic scenarios

## Thread Safety Considerations

When working with these examples, pay attention to:

- Proper mutex initialization and cleanup
- Identifying critical sections accurately
- Understanding the performance trade-offs of synchronization
- Recognizing when race conditions might not be immediately apparent
