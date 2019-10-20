//
// Created by benjamin on 19/10/2019.
//

#ifndef COMP2208_CW1_ASTAR_H
#define COMP2208_CW1_ASTAR_H

#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"
#include "Main.h"

#include <queue>
#include <vector>

struct compare
{
    bool operator()(BlockWorld* a, BlockWorld* b )
    {
        return a->getManhattan_distance() > b->getManhattan_distance();
    }
};

class AStar {

private:
    std::priority_queue<BlockWorld*, std::vector<BlockWorld*>, compare> fringe;
    int expanded_nodes;

    void expand(BlockWorld* node);

public:

    AStar(){}

    void run(BlockWorld* root);

};



#endif //COMP2208_CW1_ASTAR_H
