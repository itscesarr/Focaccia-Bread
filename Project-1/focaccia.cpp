/**
 * focaccia.cpp
  * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 *
 * Cesar Vargas
 * cavargas
 *
 * EECS 183: Project 1
 * Winter 2024
 * 
 * This project, I will write a program to help purchase the correct amount of ingredients to make focaccia bread for a party.
 *
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    //Calculates the amount of loaves per number people,
    //given the quotient: 4 people = 1 loaf
    int loafBread = ceil(static_cast<double>(people) / 4.0);
    
    //Output stating the amount of Focaccia bread needed
    //given the quotient: 4 people = 1 loaf
    cout << "You need to make: " << loafBread << " "
    << pluralize("loaf", "loaves", loafBread) << " of focaccia" << endl
    << endl;
    
    cout << "Shopping List for Focaccia Bread" << endl
         << "--------------------------------" << endl;
    
    
    //Calculates the amount of flour bags needed,
    //given number of loaves needed to make
    const double FLOUR_CUPS_PER_LOAF = 5.0;
    const double FLOUR_CUPS_PER_BAG = 20.0;
    
    double cupsPerLoaf = (ceil(loafBread * FLOUR_CUPS_PER_LOAF));
    double flourBags = (ceil(cupsPerLoaf / FLOUR_CUPS_PER_BAG));

    //Output stating the amount of flour bags needed
    cout << flourBags << pluralize(" bag"," bags", flourBags)
         << " of flour" << endl;
    
    
    //Calculates the amount of yeast packages needed,
    //given number of loaves needed to make
    const double YEAST_TEASPOON_PER_LOAF = 1.75;
    const double YEAST_TEASPOON_PER_PACKAGE = 2.25;
    double yeastPackage = (ceil(loafBread * YEAST_TEASPOON_PER_LOAF
                                / YEAST_TEASPOON_PER_PACKAGE));
    
    //Output stating the amount of yeast packages needed
    cout << yeastPackage << pluralize(" package"," packages", yeastPackage)
         << " of yeast" << endl;
    
    
    //Calculates the amount of salt cansiters needed,
    //given number of loaves needed to make
    const double SALT_TSP_PER_LOAF = 1.875;
    const double SALT_TSP_PER_CANISTER = 6.0;
    
    double saltPerLoaf = (ceil(loafBread * SALT_TSP_PER_LOAF));
    double saltCanisters = (ceil(saltPerLoaf / SALT_TSP_PER_CANISTER));

    //Output stating the amount of tablespoons of salt needed
    cout << saltCanisters << pluralize(" canister"," canisters", saltCanisters)
         << " of salt" << endl;
    
    
    //Calculates the amount of tablespoons of olive oil needed,
    //given number of loaves needed to make
    //There are 33.78 tablespoons in a bottle of olive,
    //times the amount of oill needed to make a loaf
    const double TB_OF_OLV = 2.0;
    const double TB_PER_BOTTLE_OF_OLV = 33.78;
    
    double oilPerLoaf = (ceil(loafBread * TB_OF_OLV));
    double bottleOliveOil = (ceil(oilPerLoaf / TB_PER_BOTTLE_OF_OLV));

    //Output stating the amount of olive oil needed
    cout << bottleOliveOil << pluralize(" bottle"," bottles", bottleOliveOil)
         << " of olive oil" << endl << endl;
    

    //Declares the prices for the ingredients needed
    //for the amount of loaves needed to make
    const double FLOUR_COST_PER_BAG = 2.69;
    const double YEAST_COST_PER_PACKAGE = 0.40;
    const double SALT_COST_PER_CANISTER = 0.49;
    const double COST_PER_BOTTLE_OF_OLV_OIL = 6.39;
    
    //Calculates the price of the total amount of ingredients,
    //based on the number of loaves needed to make
    double totalCost = flourBags * FLOUR_COST_PER_BAG +
                yeastPackage * YEAST_COST_PER_PACKAGE +
               saltCanisters * SALT_COST_PER_CANISTER +
           bottleOliveOil * COST_PER_BOTTLE_OF_OLV_OIL;
    
    //Output stating the total expected cost of ingredients
    cout << "Total expected cost of ingredients: " << "$" << totalCost << endl
         << endl;

    //Final statement
    cout << "Have a great party!" << endl << endl;

    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
