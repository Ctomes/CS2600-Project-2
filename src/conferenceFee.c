/*

    File name: conferenceFee.c
    Programmer: Eugene Kim

    This program will calculate the total fee generated from conference. 
    These functions don't return values directly but modifies the 
    Trip object's values 

*/
#include <stdio.h>
#include "../header/trip.h" 


void calculateConferenceExpenses(struct Trip* tripPointer) 
{
    // This function will calculate the total conference expenses
    // conference/seminar fee + hotel expenses
    getConferenceFees(tripPointer);
    getHotelFees(tripPointer);
    getMealFees(tripPointer);

}

void getConferenceFees(struct Trip* tripPointer)
{
    // This function will prompt and return the user input of conference fee
    double fee; 
    printf("Please enter conference fee: $"); 
    scanf("%f", &fee);
    tripPointer.conferenceFees = fee; 
}

void getHotelFees(struct Trip* tripPoniter)
{


}

void getMealFees(struct Trip* tripPointer)
{


}