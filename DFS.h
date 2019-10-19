//
// Created by benjamin on 14/10/2019.
//

#ifndef COMP2208_CW1_DFS_H
#define COMP2208_CW1_DFS_H

#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"
#include "Main.h"

#include <stack>

class DFS {

private:
    std::stack<BlockWorld*> fringe;
    int expanded_nodes;

    void expand(BlockWorld* node);

public:

    DFS(){}

    void run(BlockWorld* root);
};


#endif //COMP2208_CW1_DFS_H
