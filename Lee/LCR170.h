#pragma once
#include "common.h"


class  BIT
{
private:
    vector<int>trees;
    int n_;
public:
    BIT(int n) :n_(n),trees(n+1,0){
    };
    ~BIT() {
    };

    static int lowBit(int x) {
        return x & (-x);
    }



private:

};



class LCR170
{
public:
    int reversePairs(vector<int>& record) {
        
    }
};