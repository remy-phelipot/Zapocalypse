#include "Position.h"

Position::Position() {
    posX = POSITION_UNDEFINED;
    posY = POSITION_UNDEFINED;
}

Position::Position( int pPosX, int pPosY ) {
    posX = pPosX;
    posY = pPosY;
}

/*
Position less ( const Position &other ) {
    if ( posX < other.GetposX() ) {
        return true;
    }
    else if ( posX < other.GetposX() )
    return posX < ot
    her.GetposX();

}

inline bool operator<(const Foo& a, const Foo& b)
{
  return a.less(b);
}
*/
