//
// Created by benjamin on 19/10/2019.
//

#ifndef COMP2208_CW1_IDS_H
#define COMP2208_CW1_IDS_H


#include "BlockWorld.h"
#include "Block.h"
#include "Player.h"
#include "Main.h"

#include <stack>

class IDS {

private:
    BlockWorld* root;
    std::stack<BlockWorld*> fringe;
    int expanded_nodes;
    int max_depth;

    void expand(BlockWorld* node);
    void initialize(int depth);


public:

    IDS(int depth);

    void run();
};



#endif //COMP2208_CW1_IDS_H
