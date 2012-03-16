#include "Position.h"

Position::Position() {
    posX = POSITION_UNDEFINED;
    posY = POSITION_UNDEFINED;
}

Position::Position( int pPosX, int pPosY ) {
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
