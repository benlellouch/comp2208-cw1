//
// Created by benjamin on 22/10/2019.
//

#ifndef COMP2208_CW1_SEARCH_H
#define COMP2208_CW1_SEARCH_H

#include "BlockWorld.h"

#include <stack>

class Search {

private:
    BlockWorld* root;
    int number_of_nodes_generated = 0;
    int number_of_nodes_expanded = 0;
    std::stack<BlockWorld*> solution_stack;
public:
    Search (BlockWorld* node) : root(node) {}

    bool check_for_solution(BlockWorld* node);
    void print_solution(BlockWorld* node);
    void print_state(BlockWorld* node);

    std::string direction_to_string(Direction direction);

    BlockWorld* get_root() { return root;}

    int get_number_of_nodes_generated(){ return number_of_nodes_generated; }
    void increment_number_of_nodes_generated(){ number_of_nodes_generated ++;}

    int get_number_of_nodes_expanded(){ return number_of_nodes_expanded; }
    void increment_number_of_nodes_expanded(){ number_of_nodes_expanded ++;}


};


#endif //COMP2208_CW1_SEARCH_H
