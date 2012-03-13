#include "Affichage.h"

Affichage::Affichage() {
    nbHexagonX = DEFAULT_NB_HEXAGON_X;
    nbHexagonY = DEFAULT_NB_HEXAGON_Y;

// Convert the number of hexagon into the number of characters
    sizeX = pNbHexagonX * 2;
    sizeY = pNbHexagonY;

// Set console parameters
    system( "TITLE Zapocalypse v0.01 Alpha" );
}

Affichage::Affichage( int pNbHexagonX, int pNbHexagonY ) {
    nbHexagonX = pNbHexagonX;
    nbHexagonY = pNbHexagonY;

// Convert the number of hexagon into the number of characters
    sizeX = pNbHexagonX * 2;
    sizeY = pNbHexagonY;

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
            // Two different kind of lines
            if ( j % 2 == 0 ) {
                if ( i % 4 == 0 ) {
                    cout << "/ ";
                }
                else {
                    cout << "\\_";
                }
            }
            else {
                if ( i % 4 == 0 ) {
                    cout << "\\_";
                }
                else {
                    cout << "/ ";
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
        gotoxy( sizeX, 0 );
        cout << " ";
        gotoxy( 0, sizeY );
        cout << " ";
    }

// Set the cursor at the end of the grid
    gotoxy( 0, sizeY + 1 );
}

void Affichage::hexagonToSize( int *pPosX, int *pPosY ) {
        *pPosX = ( *pPosX * 2 ) + 1;
}

void Affichage::printAtPosition( int pSizeX, int pSizeY, char pLetter ) {
    int formerX, formerY;
    formerX = wherex();
    formerY = wherey();

    hexagonToSize( &pSizeX, &pSizeY );

    gotoxy( pSizeX, pSizeY );
    cout << pLetter;

// Set the cursor at its former position
    gotoxy( formerX, formerY );
}

void Affichage::clearInputZone() {
// Set the cursor at the end of the grid
    gotoxy( 0, sizeY + 1 );
    int i;
    for ( i = 0 ; i <= 100 ; i++ ) {
        cout << " ";
    }

    gotoxy( 0, sizeY + 1 );
}

int Affichage::getSizeX()
{
    return sizeX;
}

int Affichage::getSizeY()
{
    return sizeY;
}
