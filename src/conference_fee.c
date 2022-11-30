/*

    File name: conferenceFee.c
    Programmer: Eugene Kim

    This program will calculate the total fee generated from conference. 
    These functions don't return values directly but modifies the 
    Trip object's values 

*/
#include <stdio.h>
#include "../header/trip.h" 
#include "../header/conference_fee.h"

void allowableBreakfast(struct Trip* tripPointer);
void allowableLunch(struct Trip* tripPointer);
void allowableDinner(struct Trip* tripPointer);




int calculateConferenceExpenses(struct Trip* tripPointer) 
{
    // This function will calculate the total conference expenses
    // conference/seminar fee + hotel expenses
    int days = tripPointer->daysSpentOnTrip;


    // zero the variables before begin
    tripPointer->conferenceFees = 0; 
    tripPointer->conferenceFeesAllowable = 0;
    tripPointer->hotelFees = 0; 
    tripPointer->hotelFeesAllowable = 0; 
    tripPointer->mealFees = 0;
    tripPointer->mealFeesAllowable = 0;


    // loop while daysSpentOnTrip
    for(int i = 1; i <= days; i++)
    {
        tripPointer->daysSpentOnTrip = i;
        getConferenceFees(tripPointer);
        getHotelFees(tripPointer);
    }
    
    // get the meal fee
    getMealFees(tripPointer);

    return 1; // return 1 if everythings goes ok
}

void getConferenceFees(struct Trip* tripPointer)
{
    // This function will prompt and return the user input of conference fee
    // conference fee limit was not specified, Assume business will pay everything. 
    // So conferenceFee by employee is $0, all fees under business. 
    float fee; 
    int validate = 0;

    do {
        printf("Please enter conference fee for day %d: $" , tripPointer->daysSpentOnTrip); 
        validate = scanf("%f", &fee);
        fflush(stdin);
    } while ((validate != 1) || (validate == 0));
    
    tripPointer->conferenceFees += fee;
    tripPointer->conferenceFeesAllowable += fee; 
}

void getHotelFees(struct Trip* tripPointer)
{
    /* prompt the user numerOfDays times and get feeEachDay
       check the feeEachDay, if it exceed $90, exceedAmount = feeEachDay - 90 

    */
    float feeEachDay; 
    int validate = 0;

    do{
        printf("Please enter hotel fee of day %d: ", tripPointer->daysSpentOnTrip);
        validate = scanf("%f", &feeEachDay);
        fflush(stdin);
    } while((validate != 1) || (validate == 0));


    if(feeEachDay > 90.0)
    {
        // enter here when hotelFee is bigger than $90, 
        // hotelFees track total hotel fees
        // so amount employee pays added on to the exceedAmount
        // and so allowable is $90 which is max business can pay
        tripPointer->hotelFees += feeEachDay; 
        tripPointer->hotelFeesAllowable += 90.0;

    }
    else
    {
        // enter here when hotelFee is less than $90
        // so amount employee pay is none
        // and so allowable is the feeEachDay
        tripPointer->hotelFees += feeEachDay;
        tripPointer->hotelFeesAllowable += feeEachDay;
    }



}

void getMealFees(struct Trip* tripPointer)
{

    // get the depart Meal fee
    if(tripPointer->timeOfDeparture < 7.0)
    {
        // breakfast is allowed
        allowableBreakfast(tripPointer);
    }
    else if ((tripPointer->timeOfDeparture > 7.0) && (tripPointer->timeOfDeparture < 12.0))
    {
        allowableLunch(tripPointer);
    }
    else if((tripPointer->timeOfDeparture > 12.0) && (tripPointer->timeOfDeparture < 18.0))
    {
        allowableDinner(tripPointer);
    }
    else
    {
        printf("No meals allowed on the departure day.\n");
    }


    // get the arrival Meal fee
    if(tripPointer->timeOfDeparture < 8.0)
    {
        // breakfast is allowed
        allowableBreakfast(tripPointer);
    }
    else if ((tripPointer->timeOfDeparture > 8.0) && (tripPointer->timeOfDeparture < 13.0))
    {
        allowableLunch(tripPointer);
    }
    else if((tripPointer->timeOfDeparture > 13.0) && (tripPointer->timeOfDeparture < 19.0))
    {
        allowableDinner(tripPointer);
    }
    else
    {
        printf("No meals allowed on the arrival day.\n");
    }
}




void allowableBreakfast(struct Trip* tripPointer)
{
    float breakfast; 
    int validate = 0; 

    do {
        printf("Please enter the cost of the breakfast: $");
        validate = scanf("%f", &breakfast);
        fflush(stdin);
    } while ((validate != 1) || (breakfast < 0));

    tripPointer->mealFees += breakfast;
    tripPointer->mealFeesAllowable += 9.0;
}

void allowableLunch(struct Trip* tripPointer)
{
    float lunch; 
    int validate = 0; 

    do {
        printf("Please enter the cost of the lunch: $");
        validate = scanf("%f", &lunch);
        fflush(stdin);
    } while ((validate != 1) || (lunch < 0));

    tripPointer->mealFees += lunch;
    tripPointer->mealFeesAllowable += 12.0;
}

void allowableDinner(struct Trip* tripPointer)
{
    float dinner; 
    int validate = 0; 

    do {
        printf("Please enter the cost of the lunch: $");
        validate = scanf("%f", &dinner);
        fflush(stdin);
    } while ((validate != 1) || (dinner < 0));

    tripPointer->mealFees += dinner;
    tripPointer->mealFeesAllowable += 16.0;
}
