//
// Created by benjamin on 22/10/2019.
//

#ifndef COMP2208_CW1_SEARCH_H
#define COMP2208_CW1_SEARCH_H

#include "BlockWorld.h"

class Search {

private:
    BlockWorld* root;
public:
    Search (BlockWorld* node) : root(node) {}

    bool check_for_solution(BlockWorld* node);
    void print_solution(BlockWorld* node);

    std::string direction_to_string(Direction direction);

    BlockWorld* get_root() { return root;}

};


#endif //COMP2208_CW1_SEARCH_H
