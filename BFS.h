//
// Created by benjamin on 12/10/2019.
//

#ifndef COMP2208_CW1_BFS_H
#define COMP2208_CW1_BFS_H

#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"
#include "Main.h"
#include "Search.h"
#include <queue>

class BFS : public Search{

private:
    std::queue<BlockWorld*> fringe;
    int expanded_nodes;

    void expand(BlockWorld* node);

public:

    BFS(BlockWorld* node) : Search(node){}

    void run();

};


#endif //COMP2208_CW1_BFS_H
