#ifndef TRIP
#define TRIP

typedef struct Trip {
    int daysSpentOnTrip;
    float timeOfDeparture;
    float timeOfArrival;
    float airfare;

    float rentalCost;
    int milesDrivenInPrivateCar;
    float parkingFees;
    float taxiFees;

    float conferenceFees;
    float hotelFees;
    float mealFees;


} Trip;

//Declarations for funcs.
int calculateFlightExpenses(struct Trip* tripPointer);
int calculateCarExpenses(struct Trip* tripPointer);
int calculateConferenceExpenses(struct Trip* tripPointer);
int calculateMealExpenses(struct Trip* trip);
void displayToUser(struct Trip* tripPointer);
//templates: 
int calculateFlightExpenses(struct Trip* tripPointer){return 0;}
int calculateCarExpenses(struct Trip* tripPointer){return 0;}
int calculateConferenceExpenses(struct Trip* tripPointer){return 0;}
int calculateMealExpenses(struct Trip* tripPointer){return 0;}
void displayToUser(struct Trip* tripPointer){}
#endif