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
//#include "../header/flightExpenses.h"


// This struct is from dany's
struct flightExpenses(){
    int days;
    float arrival;
    float departure;
    float airfareCost;
};



// global variables
float exceedAmount = 0.0; 

void calculateConferenceExpenses(struct Trip* tripPointer) 
{
    // This function will calculate the total conference expenses
    // conference/seminar fee + hotel expenses
    int days = tripPointer->daysSpentOnTrip


    // assume business will pay conference fees.
    tripPointer->conferenceFees = 0; 


    // loop while daysSpentOnTrip
    for(int i = 1; i <= days; i++)
    {
        tripPointer->daysSpentOnTrip = i;
        getConferenceFees(tripPointer);
        getHotelFees(tripPointer);
        getMealFees(tripPointer);
    }

}

void getConferenceFees(struct Trip* tripPointer)
{
    // This function will prompt and return the user input of conference fee
    // conference fee limit was not specified, Assume business will pay everything. 
    // So conferenceFee by employee is $0, all fees under business. 
    double fee; 
    printf("Please enter conference fee: $"); 
    scanf("%f", &fee);
    tripPointer->conferenceFeesAllowable += fee; 
}

void getHotelFees(struct Trip* tripPoniter)
{
    /* prompt the user numerOfDays times and get feeEachDay
       check the feeEachDay, if it exceed $90, exceedAmount = feeEachDay - 90 

    */
    float feeEachDay; 
    printf("Please enter hotel fee of day%d: ", tripPointer->daysSpentOnTrip);
    scanf("%f", &feeEachDay);
    if(feeEachDay > 90.0)
    {
        // enter here when hotelFee is bigger than $90, 
        // hotelFees track total hotel fees
        // so amount employee pays added on to the exceedAmount
        // and so allowable is $90 which is max business can pay
        tripPoniter->hotelFees += feeEachDay; 
        tripPoniter->hotelFeesAllowable += 90.0;
        exceedAmount += (feeEachDay - 90.0); 
    }
    else
    {
        // enter here when hotelFee is less than $90
        // so amount employee pay is none
        // and so allowable is the feeEachDay
        tripPoniter->hotelFees += feeEachDay;
        tripPoniter->hotelFeesAllowable += feeEachDay;
    }


}

void getMealFees(struct Trip* tripPointer)
{
    // This function will use struct flightExpenses.h from dany's but will not modify

    // days will be in base 1

    // variables
    float exceedAmount, each;
    struct flightExpenses *flightInfo;

    for(int i = 0; i < flightInfo->days; i++)
    {
        if(i == 0)
        {
            // when it is first day
        }
        else if(i == (flightInfo.days - 1))
        {
            // when it is last day
        }
        else
        {
            // when it is not first or last day
            // prompt the user for breakfast, lunch, and dinner 
            
            // breakfast
            printf("Please enter the cost of breakfast: $");
            scanf("%f", &each);
            if(each > 9.0)
            {
                // when breakfast fee exceed allowable
                tripPointer->mealFees += each;
                tripPointer->mealFeesAllowable += 9.0;
                exceedAmount += (each - 9.0); 
            } 
            else
            {
                tripPointer->mealFeesAllowable += each; 
                tripPointer->mealFees += each; 
            }

            // lunch
            printf("Please enter the cost of the lunch: $");
            scanf("%f",&each);
            if(each > 12)
            {
                // when lunch fee exceed allowble
                tripPointer->mealFee += each;
                tripPointer->mealFeesAllowable += 12.0;
                exceedAmount += (each - 12.0); 
            }
            else
            {
                tripPointer->mealFeesAllowable += each; 
                tripPointer->mealFees += each;
            }


            // dinner
            printf("Please enter the cost of the dinner: $");
            scanf("%f", &each);
            if(each > 16.0)
            {
                tripPointer->mealFee += each;
                tripPointer->mealFeesAllowable += 16.0;
                exceedAmount += (each - 16.0); 
            }
            else 
            {
                tripPointer->mealFeesAllowable += each; 
                tripPointer->mealFees += each;
            }


        } // end else

        
    } // for-loop iteration ends



}