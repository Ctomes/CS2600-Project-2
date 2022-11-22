/*

    File name: conferenceFee.c
    Programmer: Eugene Kim

    This program will calculate the total fee generated from conference. 
    

*/
#include <stdio.h>
#include "conferenceFee.h"


void calculateConferenceExpenses(struct Trip* tripPointer) 
{
    // This function will calculate the total conference expenses
    // conference/seminar fee + hotel expenses

    


}

void getConferenceFee(struct Trip* tripPointer)
{
    // This function will prompt and return the user input of conference fee
    double fee; 
    printf("Please enter conference fee: $"); 
    scanf("%f", &fee);
    tripPointer.conferenceFees = fee; 
}