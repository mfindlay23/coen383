#ifndef SEATS_H
#define SEATS_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef struct Seat {
    char type; // customer type
    int customer_id; // customer id
    int seller_id;
} Seat;

typedef struct Auditorium {
    Seat seats[10][10];
    volatile pthread_mutex_t mutex[10];
    int reserved_seats;
    //Might be smart to keep track of seats here, and exit only when all seats are full
    //or out of customers
} Auditorium;

Auditorium* createAuditorium();
void deleteAuditorium(Auditorium* a);
void printAuditorium(Auditorium* a);


#endif