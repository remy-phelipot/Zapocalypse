#include <iostream>
using namespace std;

#include "Controller.h"

int main( int nbArgs, char *tabArgs[] ) {
    QApplication app(nbArgs, tabArgs);
// Start the controler
    Controller monControleur;
    cout << "Demarrage du controleur..." << endl;
    monControleur.Start();

    cout << endl << "Fin du programme, appuyez sur Entree pour quitter..." << endl;

   return app.exec();
}
