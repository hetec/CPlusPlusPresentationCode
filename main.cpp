#include <iostream>
#include "InfoHidingObject/Grid.h"
#include "InfoHidingObject/OpenGrid.h"

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
    OpenGrid gridWithout(5, 20, 20);
    gridWithout.mPosX = 3;
    gridWithout.mPosY = -123;
    
    gridWithout.printPos();

    // Valid values but wrong behavior
    gridWithout.setPos(0,0);    // reset the position
    gridWithout.printPos();
    gridWithout.mGap = 3;       // illegal access of the gap value
    gridWithout.setPos(50, 50); // Should result in (50,50)
                                // but doesn't because of the changed gap value
    gridWithout.printPos();
    return 0;
}