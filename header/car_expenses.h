#include "trip.h"

// bundles total costs with reimbursed costs
typedef struct allCosts
{
    int total;
    int allowed;
} allCosts;

int calculateCarExpenses(struct Trip *tripPointer);
float getValidFloat(char msg[]);
bool getValidYesNo(char msg[]);

void privateCar(struct allCosts *costs);
void taxi(struct allCosts *costs);
void rental(struct allCosts *costs);