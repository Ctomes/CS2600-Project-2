/*

    File name: conferenceFee.c
    Programmer: Eugene Kim

    This program will calculate the total fee generated from conference. 
    These functions don't return values directly but modifies the 
    Trip object's values 

*/
#include <stdio.h>
#include "../header/trip.h" 
#include "../header/conferenceFee.h"


// global variables
float exceedAmount = 0.0; 

float checkInput()
{
    float input;
    if(scanf("%f", &input) == 1)
    {
        return input;
    }
    else
    {
        printf("Please enter correct input: $");
        fflush(stdin);
        return checkInput();
    }

}

int calculateConferenceExpenses(struct Trip* tripPointer) 
{
    // This function will calculate the total conference expenses
    // conference/seminar fee + hotel expenses
    int days = tripPointer->daysSpentOnTrip;


    // assume business will pay conference fees.
    tripPointer->conferenceFees = 0; 


    // loop while daysSpentOnTrip
    for(int i = 1; i <= days; i++)
    {
        tripPointer->daysSpentOnTrip = i;
        getConferenceFees(tripPointer);
        getHotelFees(tripPointer);
        getMealFees(tripPointer,days);
    }

    return 0;
}

void getConferenceFees(struct Trip* tripPointer)
{
    // This function will prompt and return the user input of conference fee
    // conference fee limit was not specified, Assume business will pay everything. 
    // So conferenceFee by employee is $0, all fees under business. 
    float fee; 
    printf("Please enter conference fee for day %d: $" , tripPointer->daysSpentOnTrip); 
    fee = checkInput();
    tripPointer->conferenceFeesAllowable += fee; 
}

void getHotelFees(struct Trip* tripPointer)
{
    /* prompt the user numerOfDays times and get feeEachDay
       check the feeEachDay, if it exceed $90, exceedAmount = feeEachDay - 90 

    */
    float feeEachDay; 
    printf("Please enter hotel fee of day %d: ", tripPointer->daysSpentOnTrip);
    feeEachDay = checkInput();
    if(feeEachDay > 90.0)
    {
        // enter here when hotelFee is bigger than $90, 
        // hotelFees track total hotel fees
        // so amount employee pays added on to the exceedAmount
        // and so allowable is $90 which is max business can pay
        tripPointer->hotelFees += feeEachDay; 
        tripPointer->hotelFeesAllowable += 90.0;
        exceedAmount += (feeEachDay - 90.0); 
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
    float exceedAmount, breakfast, lunch, dinner;

    // prompt the users and get the cost of each meal
    printf("Please enter the cost of breakfast: $");
    breakfast = checkInput();
    printf("Please enter the cost of lunch: $");
    lunch = checkInput();
    printf("Please enter the cost of dinner: $");
    dinner = checkInput();



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
            exceedAmount += breakfast;
            allowableLunch(tripPointer,lunch);
            allowableDinner(tripPointer,dinner);
        }
        else if((tripPointer->timeOfDeparture > 12.0) && (tripPointer->timeOfDeparture < 18.0))
        {
            tripPointer->mealFees += (breakfast + lunch);
            exceedAmount += (breakfast + lunch);
            allowableDinner(tripPointer,dinner);
        }
        else
        {
            tripPointer->mealFees += (breakfast + lunch + dinner);
            exceedAmount += (breakfast + lunch + dinner);
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
            exceedAmount += dinner; 
        }
        else if((tripPointer->timeOfArrival > 8.0) && (tripPointer->timeOfArrival < 13.0))
        {
            allowableBreakfast(tripPointer, breakfast);
            tripPointer->mealFees += (dinner + lunch);
            exceedAmount += (dinner + lunch); 
        }
        else 
        {
            tripPointer->mealFees += (dinner + lunch + breakfast);
            exceedAmount += (dinner + lunch + breakfast); 
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
        exceedAmount += (breakfast - 9.0); 
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
        exceedAmount += (lunch - 12.0); 
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
        exceedAmount += (dinner - 16.0); 
    }
    else 
    {
        tripPointer->mealFeesAllowable += dinner; 
        tripPointer->mealFees += dinner;
    }
}