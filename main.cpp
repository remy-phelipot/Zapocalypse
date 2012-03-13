#include <iostream>
using namespace std;

#include "Affichage.h"
#include "Controller.h"

int main( int nbArgs, char *tabArgs[] ) {
// Set the console size
    system( "MODE CON: COLS=150 LINES=50" );

// Start the controler
    Controller monControleur;
    cout << "Demarrage du controleur..." << endl;
    monControleur.Start( atoi( tabArgs[1] ), atoi( tabArgs[2] ) );

    cout << endl << "Fin du programme, appuyez sur Entree pour quitter..." << endl;
    getch();
    return 0;
}
