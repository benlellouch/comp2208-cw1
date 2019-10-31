//
// Created by benjamin on 14/10/2019.
//

#ifndef COMP2208_CW1_DFS_H
#define COMP2208_CW1_DFS_H

#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"
#include "Main.h"
#include "Search.h"

#include <stack>

class DFS : public Search{

private:
    std::stack<BlockWorld*> fringe;
    int expanded_nodes;

    void expand(BlockWorld* node);

public:

    DFS(BlockWorld* node) : Search(node){}

    void run();
};


#endif //COMP2208_CW1_DFS_H
