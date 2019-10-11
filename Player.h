//
// Created by benjamin on 11/10/2019.
//

#ifndef COMP2208_CW1_PLAYER_H
#define COMP2208_CW1_PLAYER_H

#include "Object.h"


class Player : public Object
{
public:

    Player ( int x, int y ) : Object ( x, y ) {}

    bool setX_pos ( int x );
    bool setY_pos ( int y );
};


#endif //COMP2208_CW1_PLAYER_H
