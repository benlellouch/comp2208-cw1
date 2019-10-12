//
// Created by benjamin on 12/10/2019.
//

#ifndef COMP2208_CW1_BFS_H
#define COMP2208_CW1_BFS_H

#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"

class BFS {

private:
    std::queue<BlockWorld*> fringe;
    int expanded_nodes;

    void expand(BlockWorld* node);
    void print_solution(BlockWorld* node);

public:

    BFS();

    void run(BlockWorld* root);

};


#endif //COMP2208_CW1_BFS_H
