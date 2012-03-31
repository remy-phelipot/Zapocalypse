#include "Zombie.h"
#include "World.h"

Zombie::Zombie() {
    onMove = false;
// Image of a Zombie : Z
    setImage( ZOMBIE_IMAGE );
// Type of a Zombie
    setType( zombieType );
}

Zombie::Zombie( int pPosX, int pPosY, World *pMyWorld ) :
Element( pPosX, pPosY ),
Human ( pPosX, pPosY, pMyWorld ) {
    cout << "Zombie : parameterized constructor." << endl;
    onMove = false;
// Image of a Zombie : Z
    setImage( ZOMBIE_IMAGE );
// Type of a Zombie
    setType( zombieType );
}

bool Zombie::Action() {
    if ( onMove ) {
        cout << "Zombie basic action, moving..." << endl;
        MoveObject();
        onMove = !onMove;
    }
    else {
        onMove = !onMove;
    }

// No problem
    return true;
// If there is a problem, return false and delete the element (fail)
}
