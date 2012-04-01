#include "Element.h"

Element::Element() :
myPosition() {
    cout << "Element : default constructor." << endl;
}

Element::Element( int pPosX, int pPosY ) :
myPosition( pPosX, pPosY ) {
    cout << "Element : parameterized constructor." << endl;
}

bool Element::Action() {
    cout << "Error : default action" << endl;
    return false;
}

Position Element::getMyPosition() {
    return myPosition;
}

void Element::setMyPosition( int pPosX, int pPosY ) {
    myPosition.SetposX( pPosX );
    myPosition.SetposY( pPosY );
}

void Element::setImage( char pImage ) {
    image = pImage;
}

char Element::getImage() {
    return image;
}

void Element::setType ( ItemType pType ) {
    type = pType;
}

ItemType Element::getType () {
    return type;
}
