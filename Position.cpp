#include "Position.h"

Position::Position() {
    posX = POSITION_UNDEFINED;
    posY = POSITION_UNDEFINED;
}

Position::Position( int pPosX, int pPosY ) {
    posX = pPosX;
    posY = pPosY;
}
