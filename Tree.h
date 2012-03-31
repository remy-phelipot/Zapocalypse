#ifndef TREE_H
#define TREE_H

#include "Resource.h"
#include "World.h"

#define TREE_IMAGE 'T'
#define TREE_DEFAULT_FOOD 5
#define TREE_DEFAULT_WOOD 30

class Tree : public Resource {
    public:
        /** Default constructor */
        Tree();
        Tree( int, int, World* );
    private:
        string name;
        void initTree();
        bool Action();
};

#endif // TREE_H
