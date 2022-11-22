// File name: conferenceFee.h
// Programmer: Eugene Kim


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

// function prototype list
int calculateConferenceExpenses(struct Trip trip);
double getConferenceFee(struct Trip* tripPointer);
