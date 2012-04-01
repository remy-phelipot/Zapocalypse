#include "Tree.h"

Tree::Tree() {
    initTree();
}

Tree::Tree( int pPosX, int pPosY, World *pMyWorld ) :
Element( pPosX, pPosY ),
Resource( TREE_DEFAULT_FOOD, TREE_DEFAULT_WOOD, pPosX, pPosY ) {
    cout << "Tree : parameterized constructor." << endl;
    initTree();
}

bool Tree::Action() {
    cout << "Tree basic action..." << endl;
    return true;
}

void Tree::initTree() {
    name = "BasicTree";
// Set image and type
    setImage( TREE_IMAGE );
    setType( treeType );
}
