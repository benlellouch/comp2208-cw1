//
// Created by benjamin on 11/10/2019.
//

#ifndef COMP2208_CW1_BLOCK_H
#define COMP2208_CW1_BLOCK_H

#include <string>

#include "Object.h"


class Block : public Object {

private:

    std::string name;

public:

    Block ( int x, int y, std::string name) : Object (x,y), name(name) {}

    std::string getName () { return name; }
};


#endif //COMP2208_CW1_BLOCK_H
