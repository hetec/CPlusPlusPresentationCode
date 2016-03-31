//
// Created by hebner on 31.03.2016.
//

#ifndef CODECPLUSPLUS_MESH_H
#define CODECPLUSPLUS_MESH_H

#include <iostream>

class Grid{
private:
    int mGap;
    int mNumberX;
    int mNumberY;

    int mPosX = 0;
    int mPosY = 0;

    //Checks if the assigned values are outside of max gird positions
    bool checkBounderies(int x, int y){
        //std::cout << "Number X: " << mNumberX << std::endl;
        //std::cout << "Number Y: " << mNumberY << std::endl;
        bool bounderiesOk = (!(y < 0 || y > mNumberY) && !(x < 0 || x > mNumberX));
        //std::cout << "OK: " << bounderiesOk << std::endl;
        return bounderiesOk;
    }

    void snapToPoint(int x, int y){
        int nextX;
        int nextY;
        float halfGap = mGap/2.0;
        //std::cout << "Half gap: " << halfGap << std::endl;

        //Determine X
        int diffX = x % mGap;
        //std::cout << "diffX: " << diffX << std::endl;
        if(diffX == 0){
            nextX = x;
        } else if(diffX >= halfGap){
            nextX = (x / mGap) * mGap + mGap;
        } else {
            nextX = (x / mGap) * mGap;
        }

        //Determine Y
        int diffY = y % mGap;
        //std::cout << "diffY: " << diffY << std::endl;
        if(diffY == 0){
            nextY = y;
        } else if(diffY >= halfGap){
            nextY = (y / mGap) * mGap + mGap;
        } else {
            nextY = (y / mGap) * mGap;
        }

        //Set X and Y
        this->mPosX = nextX;
        this->mPosY = nextY;

    }

public:
    Grid(int gap, int maxX, int maxY) : mGap(gap), mNumberX(maxX * gap), mNumberY(maxY * gap){
    }

    // Sets the position on the Grid
    void setPos(int x, int y){
        bool bounderiesOk = checkBounderies(x, y);
        if(bounderiesOk){
            snapToPoint(x, y);
        } else{
            std::cout << "Your point is outside of the defined bounderies: X_max = " << mNumberX << ", Y_max = " << mNumberY << std::endl;
        }
    }

    // Print the current position
    void printPos(){
        std::cout << "Your point is on the position: (" << mPosX << ", " << mPosY << ")" << std::endl;
    }
};

#endif //CODECPLUSPLUS_MESH_H
