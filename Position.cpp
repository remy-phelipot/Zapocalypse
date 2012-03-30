#include "Position.h"

Position::Position() {
    cout << "Position : default constructor." << endl;
    posX = POSITION_UNDEFINED;
    posY = POSITION_UNDEFINED;
}

Position::Position( int pPosX, int pPosY ) {
    cout << "Position : parameterized constructor, x=" << pPosX << " y=" << pPosY << endl;
    posX = pPosX;
    posY = pPosY;
}

bool Position::operator < ( const Position &pPos ) const {
    if ( posX < pPos.GetposX() ) {
        return true;
    }
    else {
        if ( posX > pPos.GetposX() ) {
            return false;
        }
        else {
            if ( posY < pPos.GetposY() ) {
                return true;
            }
            else {
                if ( posY > pPos.GetposY() ) {
                    return false;
                }
            }
        }
    }
    return false;
}
