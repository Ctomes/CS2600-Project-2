#ifndef TRIP
#define TRIP

typedef struct Trip
{
    int daysSpentOnTrip;
    float timeOfDeparture;
    float timeOfArrival;
    float airfare;

    float allowedCarCost;
    float totalCarCost;

    float conferenceFees;
    float conferenceFeesAllowable;
    float hotelFees;
    float hotelFeesAllowable;
    float mealFees;
    float mealFeesAllowable; // never higher than $16 + $16

} Trip;

#endif