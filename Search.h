//
// Created by benjamin on 22/10/2019.
//

#ifndef COMP2208_CW1_SEARCH_H
#define COMP2208_CW1_SEARCH_H

#include "BlockWorld.h"

class Search {

private:
    BlockWorld* root;
    int number_of_nodes_generated = 0;
public:
    Search (BlockWorld* node) : root(node) {}

    bool check_for_solution(BlockWorld* node);
    void print_solution(BlockWorld* node);

    std::string direction_to_string(Direction direction);

    BlockWorld* get_root() { return root;}

    int get_number_of_nodes_generated(){ return number_of_nodes_generated; }
    void increment_number_of_nodes_generated(){ number_of_nodes_generated ++;}


};


#endif //COMP2208_CW1_SEARCH_H
