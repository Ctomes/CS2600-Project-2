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

// Declarations for funcs. (here?)
 //int calculateCarExpenses(struct Trip *tripPointer);
  //int calculateConferenceExpenses(struct Trip *tripPointer);
 //int calculateMealExpenses(struct Trip *trip);
// templates: [caused multiple definition errors]

// int calculateConferenceExpenses(struct Trip *tripPointer) { return 0; }
 //int calculateMealExpenses(struct Trip *tripPointer) { return 0; }
 
#endif