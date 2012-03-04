#include "Affichage.h"

Affichage::Affichage( int pNbHexagonX, int pNbHexagonY ) {
    nbHexagonX = pNbHexagonX;
    nbHexagonY = pNbHexagonY;

// Convert the number of hexagon into the number of characters
    sizeX = pNbHexagonX * 2;
    sizeY = pNbHexagonY * 2;

// Set console parameters
    system( "TITLE Zapocalypse v0.01 Alpha" );
}

void Affichage::printGrid() {
// Clear screen
    clrscr();

    int i, j;
    i = j = 0;
    gotoxy( i, j );

// Print the grid
    for ( j = 0 ; j <= sizeY ; j++ ) {
        for ( i = 0 ; i <= sizeX ; i = i + 2 ) {
            gotoxy( i, j );
// Two different king of lines
            if ( j % 2 == 0 ) {
                if ( i % 4 == 0 ) {
                    cout << "\\_";
                }
                else {
                    cout << "/ ";
                }
            }
            else {
                if ( i % 4 == 0 ) {
                    cout << "/ ";
                }
                else {
                    cout << "\\_";
                }
            }
        }
    }

// Clear the border of the grid
    for ( j = 0 ; j <= sizeY ; j++ ) {
        gotoxy( sizeX + 1, j );
        cout << " ";
    }

// Clear the corners of the grid
    if ( nbHexagonX % 2 == 0 ) {
        gotoxy( sizeX, sizeY );
        cout << " ";
    }
    else {
        gotoxy( sizeX, 0 );
        cout << " ";
    }

    gotoxy( 0, 0 );
    cout << " ";

// Set the cursor at the end of the grid
    gotoxy( 0, sizeY );
}

void Affichage::hexagonToSize( int *pPosX, int *pPosY ) {
    *pPosX *= 2;
    *pPosY *= 2;
}
