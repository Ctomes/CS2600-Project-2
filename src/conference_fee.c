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

void allowableBreakfast(struct Trip* tripPointer, float breakfast);
void allowableLunch(struct Trip* tripPointer, float lunch);
void allowableDinner(struct Trip* tripPointer, float dinner);




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


    // loop while daysSpentOnTrip
    for(int i = 1; i <= days; i++)
    {
        tripPointer->daysSpentOnTrip = i;
        getConferenceFees(tripPointer);
        getHotelFees(tripPointer);
        getMealFees(tripPointer,days);
    }

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

void getMealFees(struct Trip* tripPointer, int totalDays)
{
    // This function will use struct flightExpenses.h from dany's but will not modify

    // days will be in base 1

    // variables
    float breakfast, lunch, dinner;
    int validate = 0; 

    // prompt the users and get the cost of each meal
    do{
        printf("Please enter the cost of breakfast: $");
        validate = scanf("%f", &breakfast);
        fflush(stdin);
    } while ((validate != 1) || (validate == 0));

    do{
        validate = 0;
        printf("Please enter the cost of lunch: $");
        validate = scanf("%f", &lunch);
        fflush(stdin);
    } while ((validate != 1) || (validate == 0));

    do{
        validate = 0;
        printf("Please enter the cost of dinner: $");
        validate = scanf("%f", &dinner);
        fflush(stdin);
    } while ((validate != 1) || (validate == 0));

    // sort the cost into correct category
    if(tripPointer->daysSpentOnTrip == 0)
    {
        // enter here when it is first day 
        if(tripPointer->timeOfDeparture < 7.0)
        {
            allowableBreakfast(tripPointer, breakfast);
            allowableLunch(tripPointer,lunch);
            allowableDinner(tripPointer,dinner);
        }
        else if((tripPointer->timeOfDeparture > 7.0) && (tripPointer->timeOfDeparture < 12.0))
        {
            tripPointer->mealFees += breakfast;
            allowableLunch(tripPointer,lunch);
            allowableDinner(tripPointer,dinner);
        }
        else if((tripPointer->timeOfDeparture > 12.0) && (tripPointer->timeOfDeparture < 18.0))
        {
            tripPointer->mealFees += (breakfast + lunch);
            allowableDinner(tripPointer,dinner);
        }
        else
        {
            tripPointer->mealFees += (breakfast + lunch + dinner);

        }
    } // end if
    else if((tripPointer->daysSpentOnTrip + 1) == totalDays)
    {
        // enter here when it is last day
        if(tripPointer->timeOfArrival > 19.0)
        {
            allowableBreakfast(tripPointer, breakfast);
            allowableLunch(tripPointer,lunch);
            allowableDinner(tripPointer,dinner);
        }
        else if((tripPointer->timeOfArrival > 13.0) && (tripPointer->timeOfArrival < 19.0))
        {
            allowableBreakfast(tripPointer, breakfast);
            allowableLunch(tripPointer,lunch);  
            tripPointer->mealFees += dinner;

        }
        else if((tripPointer->timeOfArrival > 8.0) && (tripPointer->timeOfArrival < 13.0))
        {
            allowableBreakfast(tripPointer, breakfast);
            tripPointer->mealFees += (dinner + lunch);

        }
        else 
        {
            tripPointer->mealFees += (dinner + lunch + breakfast);

        }
    } // end else-if
    else 
    {
        //enter here when it is not first or last day
        allowableBreakfast(tripPointer, breakfast);
        allowableLunch(tripPointer,lunch);
        allowableDinner(tripPointer,dinner);
    } // end else

}

void allowableBreakfast(struct Trip* tripPointer, float breakfast)
{
    if(breakfast > 9.0)
    {
        // when breakfast fee exceed allowable
        tripPointer->mealFees += breakfast;
        tripPointer->mealFeesAllowable += 9.0;

    } 
    else
    {
        tripPointer->mealFeesAllowable += breakfast; 
        tripPointer->mealFees += breakfast; 
    }
}

void allowableLunch(struct Trip* tripPointer, float lunch)
{
    if(lunch > 12)
    {
        // when lunch fee exceed allowble
        tripPointer->mealFees += lunch;
        tripPointer->mealFeesAllowable += 12.0;

    }
    else
    {
        tripPointer->mealFeesAllowable += lunch; 
        tripPointer->mealFees += lunch;
    }
}

void allowableDinner(struct Trip* tripPointer, float dinner)
{
    if(dinner > 16.0)
    {
        tripPointer->mealFees += dinner;
        tripPointer->mealFeesAllowable += 16.0;

    }
    else 
    {
        tripPointer->mealFeesAllowable += dinner; 
        tripPointer->mealFees += dinner;
    }
}