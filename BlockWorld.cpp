//
// Created by benjamin on 11/10/2019.
//

#include "BlockWorld.h"

BlockWorld::BlockWorld(BlockWorld* parent, Direction move) :
parent(parent),
player(parent->getPlayer()),
blocks(parent->getBlocks()),
move_taken(move)
{
    calculate_possible_move();
}

void BlockWorld::calculate_possible_move()
{
    if((player.getY_pos() + 1) < grid_size)
    {
        possible_moves.push_back(up);
    }
    if((player.getY_pos() - 1) >= 0)
    {
        possible_moves.push_back(down);
    }
    if((player.getX_pos() + 1) < grid_size)
    {
        possible_moves.push_back(right);
    }
    if((player.getX_pos() - 1) >= 0)
    {
        possible_moves.push_back(left)
    }
}

void BlockWorld::move(Direction direction)
{
    switch (direction)
    {
        case up:
            move_up();
            break;
        case down:
            move_down();
            break;
        case left:
            move_left();
            break;
        case right:
            move_right();
            break;
    }
}

void BlockWorld::move_up()
{
    int previous_player_y_pos = player.getY_pos();
    player.setX_pos(previous_player_y_pos + 1);
    for(Block block : blocks)
    {
        if(block.getY_pos() == player.getY_pos())
        {
            block.setY_pos(previous_player_y_pos);
        }
    }
}

void BlockWorld::move_down()
{
    int previous_player_y_pos = player.getY_pos();
    player.setX_pos(previous_player_y_pos - 1);
    for(Block block : blocks)
    {
        if(block.getY_pos() == player.getY_pos())
        {
            block.setY_pos(previous_player_y_pos);
        }
    }
}

void BlockWorld::move_left()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos - 1);
    for(Block block : blocks)
    {
        if(block.getX_pos() == player.getX_pos())
        {
            block.setX_pos(previous_player_x_pos);
        }
    }
}
void BlockWorld::move_right()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos + 1);
    for(Block block : blocks)
    {
        if(block.getX_pos() == player.getX_pos())
        {
            block.setX_pos(previous_player_x_pos);
        }
    }
}