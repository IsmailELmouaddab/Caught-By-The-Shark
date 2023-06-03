#include "TabRequin.h"
#include "TabCorail.h"
#include "TabPerso.h"
#include "Perso.h"
#include <iostream>
using namespace std;

int main() {
    TabRequin requins;
    requins.testRegression();

    TabCorail coraux;
    coraux.testRegression();

    Perso persoTest;
    persoTest.testRegression();

    TabPerso tabPersonnage;
    tabPersonnage.testRegression();

    return 0;
}
