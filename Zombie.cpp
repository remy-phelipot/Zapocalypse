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
