#pragma once
#include "common.h"


class  BITA
{
private:
    vector<int>trees;
    size_t n_;
public:
    BITA(size_t n) :n_(n),trees(n+1,0){
    };
    ~BITA() {
    };

    static int lowBit(int x) {
        return x & (-x);
    }

    void update(int x, int delta) {
        while (x <= n_) {
            trees[x] += delta;
            x += lowBit(x);
        }
    }

    int query(int x) {
        int count = 0;
        while (x > 0) {
            count += trees[x];
            x -= lowBit(x);
        }
        return count;
    }



private:

};



class LCR170
{
public:
    int reversePairs(vector<int>& record) {
        int ans = 0;

        vector<int> tmp = record;
        sort(tmp.begin(), tmp.end());

        for (int& num : record) {
           // num =( lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() )  + 1;
            num =static_cast<int>( lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() )+ 1;
        }  

        BITA bit(record.size() + 1);

        for (int i = record.size() - 1; i >= 0; i--) {
            ans += bit.query(record.at(i) - 1);
            bit.update(record.at(i),1);
        }


        return ans;
    }
};