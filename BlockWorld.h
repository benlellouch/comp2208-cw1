//
// Created by benjamin on 11/10/2019.
//

#ifndef COMP2208_CW1_BLOCKWORLD_H
#define COMP2208_CW1_BLOCKWORLD_H

#include <vector>
#include <iostream>

#include "Player.h"
#include "Block.h"

enum Direction { up = 'u', down = 'd', left = 'l', right = 'r'};

static const int grid_size = 4;

class BlockWorld {

private:

    BlockWorld* parent;
    Player player;
    std::vector<Block> blocks;
    Direction move_taken;
    std::vector<Direction> possible_moves;
    int depth;
    int manhattan_distance;

    void calculate_possible_move();

    void move_up();
    void move_down();
    void move_left();
    void move_right();

    void calculate_up();
    void calculate_down();
    void calculate_left();
    void calculate_right();
    void calculate_manhattan_distance();

public:

    BlockWorld();
    BlockWorld(BlockWorld* parent, Direction move);
    BlockWorld(int x_player, int y_player, int x_a, int y_a, int x_b, int y_b, int x_c, int y_c);

    BlockWorld* getParent() { return parent; }
    Player getPlayer() { return player; }
    std::vector<Block> getBlocks() { return blocks; }
    Direction getMove() { return move_taken; }
    std::vector<Direction> getPossible_moves() { return possible_moves; }
    int getDepth() { return depth; }
    int getManhattan_distance() const { return  manhattan_distance; }

    void move(Direction direction);

};


#endif //COMP2208_CW1_BLOCKWORLD_H
