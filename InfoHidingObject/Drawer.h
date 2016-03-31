//
// Created by hebner on 31.03.2016.
//

#ifndef CODECPLUSPLUS_DRAWER_H
#define CODECPLUSPLUS_DRAWER_H

#include "Grid.h"

class Drawer {

private:
    Grid grid;


public:

    Drawer(Grid g) : grid(g) {

    }

    void drawLine(int x1, int y1, int x2, int y2){
        grid.setPos(x1, y1);
        int newX1 = grid.mPosX; // Direct access to the private member variables
        int newY1 = grid.mPosY; // Because Drawer is a FRIEND Class
        grid.setPos(x2, y2);
        int newX2 = grid.mPosX;
        int newY2 = grid.mPosY;

        std::cout << "Your line goes from (" << newX1 << ", " << newY1 << ") to (" << newX2 << ", " << newY2 << ")";
    }


};

#endif //CODECPLUSPLUS_DRAWER_H
