#include <iostream>
using namespace std;

#include "Controller.h"
#include "Affichage.h"

int main( int nbArgs, char *tabArgs[] ) {
// Set the size
    system( "MODE CON: COLS=150 LINES=50" );

    Affichage monAffichage( atoi( tabArgs[1] ), atoi( tabArgs[2] ) );
    Controller monControleur( monAffichage );
    cout << "Demarrage du controleur..." << endl;
    monControleur.start();

    cout << endl << "Fin du programme..." << endl;
    return 0;
}
