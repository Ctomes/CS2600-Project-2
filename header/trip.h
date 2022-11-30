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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#endif