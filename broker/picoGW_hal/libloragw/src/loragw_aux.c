/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2017 Semtech-Cycleo

Description:
    LoRa concentrator HAL auxiliary functions

License: Revised BSD License, see LICENSE.TXT file include in the project

*/


/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

/* fix an issue between POSIX and C99 */
#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>  /* printf fprintf */
#include <time.h>   /* clock_nanosleep */

/* -------------------------------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */

#if DEBUG_AUX == 1
#define DEBUG_MSG(str)                fprintf(stderr, str)
#define DEBUG_PRINTF(fmt, args...)    fprintf(stderr,"%s:%d: "fmt, __FUNCTION__, __LINE__, args)
#else
#define DEBUG_MSG(str)
#define DEBUG_PRINTF(fmt, args...)
#endif

/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS DEFINITION ------------------------------------------ */

/* This implementation is POSIX-pecific and require a fix to be compatible with C99 */


void wait_ms_linux(unsigned long a) {
    struct timespec dly;
    struct timespec rem;

    dly.tv_sec = a / 1000;
    dly.tv_nsec = ((long)a % 1000) * 1000000;

    DEBUG_PRINTF("NOTE dly: %ld sec %ld ns\n", dly.tv_sec, dly.tv_nsec);

    if((dly.tv_sec > 0) || ((dly.tv_sec == 0) && (dly.tv_nsec > 100000))) {
        clock_nanosleep(CLOCK_MONOTONIC, 0, &dly, &rem);
        DEBUG_PRINTF("NOTE remain: %ld sec %ld ns\n", rem.tv_sec, rem.tv_nsec);
    }
    return;
}

void wait_ns_linux(unsigned long a) {
    struct timespec dly;
    struct timespec rem;

    dly.tv_sec = 0;
    dly.tv_nsec = a;

    DEBUG_PRINTF("NOTE dly: %ld sec %ld ns\n", dly.tv_sec, dly.tv_nsec);

    if((dly.tv_sec > 0) || ((dly.tv_sec == 0) && (dly.tv_nsec > 1))) {
        clock_nanosleep(CLOCK_MONOTONIC, 0, &dly, &rem);
        DEBUG_PRINTF("NOTE remain: %ld sec %ld ns\n", rem.tv_sec, rem.tv_nsec);
    }
    return;
}

void wait_ms(unsigned long a) {
#ifdef _WIN32
    return wait_ms_win(a) ;
#elif __linux__
    return wait_ms_linux(a) ;
#elif __APPLE__
    DEBUG_PRINTF("System is not recognized.");
#elif __unix__
    DEBUG_PRINTF("System is not recognized.");
#elif __posix__
    DEBUG_PRINTF("System is not recognized.");
#else
    DEBUG_PRINTF("System is not recognized.");
#endif
}
void wait_ns(unsigned long a) {
#ifdef _WIN32
    return wait_ns_win(a) ;
#elif __linux__
    return wait_ns_linux(a) ;
#elif __APPLE__
    DEBUG_PRINTF("System is not recognized.");
#elif __unix__
    DEBUG_PRINTF("System is not recognized.");
#elif __posix__
    DEBUG_PRINTF("System is not recognized.");
#else
    DEBUG_PRINTF("System is not recognized.");
#endif
}

/* --- EOF ------------------------------------------------------------------ */
