//
// Created by benjamin on 11/10/2019.
//

#include "BlockWorld.h"

BlockWorld::BlockWorld() :
parent(nullptr),
player(3,0)
{
    blocks.push_back(Block(0,0,"A"));
    blocks.push_back(Block(1,0,"B"));
    blocks.push_back(Block(2,0,"C"));
    calculate_possible_move();
}

BlockWorld::BlockWorld(BlockWorld* parent, Direction direction) :
        parent(parent),
        player(parent->getPlayer()),
        blocks(parent->getBlocks()),
        move_taken(direction)
{
    move(direction);
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
        possible_moves.push_back(left);
    }
}

void BlockWorld::move(Direction direction)
{
    switch (direction)
    {
        case up:
            std::cout << "I go up \n";
            move_up();
            break;
        case down:
            std::cout << "I go down \n";
            move_down();
            break;
        case left:
            std::cout << "I go left \n";
            move_left();
            break;
        case right:
            std::cout << "I go right \n";
            move_right();
            break;
    }
}

void BlockWorld::move_up()
{
    int previous_player_y_pos = player.getY_pos();
    std::cout << "Previous player y position: " << previous_player_y_pos << "\n";
    player.setY_pos(previous_player_y_pos + 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos())
        {
            std::cout << "I do acknowledge the collision " << previous_player_y_pos << "\n";
            block->setY_pos(previous_player_y_pos);
            std::cout << "Block new position: " << block->getY_pos() << " for " << block->getName()<< "\n";
        }
    }
//    for(Block block : blocks)
//    {
//        if(block.getY_pos() == player.getY_pos())
//        {
//            block.setY_pos(previous_player_y_pos);
//        }
//    }
}

void BlockWorld::move_down()
{
    int previous_player_y_pos = player.getY_pos();
    player.setY_pos(previous_player_y_pos - 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getY_pos() == player.getY_pos())
        {
            std::cout << "I do acknowledge the collision " << previous_player_y_pos << "\n";
            block->setY_pos(previous_player_y_pos);
            std::cout << "Block new position: " << block->getY_pos() << " for " << block->getName()<< "\n";
        }
    }
//    for(Block block : blocks)
//    {
//        if(block.getY_pos() == player.getY_pos())
//        {
//            block.setY_pos(previous_player_y_pos);
//        }
//    }
}

void BlockWorld::move_left()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos - 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getX_pos() == player.getX_pos())
        {
            std::cout << "I do acknowledge the collision " << previous_player_x_pos << "\n";
            block->setX_pos(previous_player_x_pos);
            std::cout << "Block new position: " << block->getX_pos() << " for " << block->getName()<< "\n";
        }
    }
//    for(Block block : blocks)
//    {
//        if(block.getX_pos() == player.getX_pos())
//        {
//            std::cout << "I do acknowledge the collision " << previous_player_x_pos << "\n";
//            block.setX_pos(previous_player_x_pos);
//            std::cout << "Block new position: " << block.getX_pos() << " for " << block.getName()<< "\n";
//        }
//    }
}
void BlockWorld::move_right()
{
    int previous_player_x_pos = player.getX_pos();
    player.setX_pos(previous_player_x_pos + 1);

    for (std::vector<Block>::iterator block = blocks.begin(); block != blocks.end(); ++block)
    {
        if(block->getX_pos() == player.getX_pos())
        {
            std::cout << "I do acknowledge the collision " << previous_player_x_pos << "\n";
            block->setX_pos(previous_player_x_pos);
            std::cout << "Block new position: " << block->getX_pos() << " for " << block->getName()<< "\n";
        }
    }
//    for(Block block : blocks)
//    {
//        if(block.getX_pos() == player.getX_pos())
//        {
//            block.setX_pos(previous_player_x_pos);
//        }
//    }
}