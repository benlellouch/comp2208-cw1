//
// Created by benjamin on 11/10/2019.
//

#ifndef COMP2208_CW1_OBJECT_H
#define COMP2208_CW1_OBJECT_H


class Object {

private:

    int x_pos, y_pos;

public:

    Object(int x, int y) : x_pos(x), y_pos(y) {};

    int getX_pos() { return x_pos;}
    int getY_pos() { return y_pos;}

    bool setX_pos ( int x ) { x_pos = x; return true; }
    bool setY_pos ( int y ) { y_pos = y; return true; }

};


#endif //COMP2208_CW1_OBJECT_H
