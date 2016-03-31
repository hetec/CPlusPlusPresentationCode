#include <iostream>
#include "InfoHidingObject/Grid.h"
#include "InfoHidingObject/OpenGrid.h"
#include "InfoHidingObject/Drawer.h"

using namespace std;

int main() {

    // Grid with encapsulation
    //////////////////////////

    // Set valid grid position and use auto snapping
    Grid gridWith(5, 20, 20);
    gridWith.setPos(89,62);     // Results in (90,60) because of five steps
    gridWith.printPos();

    // Set value outside the grid
    gridWith.setPos(105, 16);   // Error message

    // Grid without encapsulation
    /////////////////////////////

    // Set x and y directly to invalid values
//    OpenGrid gridWithout(5, 20, 20);
//    gridWithout.mPosX = 3;
//    gridWithout.mPosY = -123;
//
//    gridWithout.printPos();
//
//    // Valid values but wrong behavior
//    gridWithout.setPos(0,0);    // reset the position
//    gridWithout.printPos();
//    gridWithout.mGap = 3;       // illegal access of the gap value
//    gridWithout.setPos(50, 50); // Should result in (50,50)
//                                // but doesn't because of the changed gap value
//    gridWithout.printPos();

    // Grid with encapsulation as FRIEND
    ////////////////////////////////////

//    // Access private member variable directly since main is a FRIEND
//    Grid gridWith2(5, 20, 20);
//    gridWith2.mPosX = 5;
//    gridWith2.mPosY = 33; // invalid only multiples of 5 are allowed
//    gridWith2.printPos();
//
//    // Set gap to an invalid value
//    gridWith2.mGap = 12;
//    gridWith2.setPos(5, 5); // Results in (0, 0) because of the wrong gap
//    gridWith2.printPos();

    // Grid with encapsulation and FRIEND class
    ///////////////////////////////////////////

    Grid gridWith3(5, 20, 20);
    Drawer drawer(gridWith3);
    drawer.drawLine(3, 12, 78, 99); // Method uses private member variables
    return 0;
}