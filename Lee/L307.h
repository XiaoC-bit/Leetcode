#pragma once
#include "common.h"

class BIT307 {
private:
    vector<int> datas;
    size_t n;
public:
    BIT307() 
    {

    }

    static int lowbit(int x) {
        return x & (-x);
    }

    void init(size_t count) {
        datas = vector<int>(count + 1, 0);
        n = count;
    }

    int query(int x) {
        int res=0;
        while (x) {
            res += datas.at(x);
            x -= lowbit(x);
        }

        return res;
    }

    void update(int x, int data) {
        while (x <=n) {
            datas.at(x) += data;
            x += lowbit(x);
        }
    }
};

class NumArray
{
private:
    BIT307 bit;
public:
    NumArray(vector<int>& nums) {
        bit.init(nums.size());

        for (size_t i = 0; i < nums.size(); i++) {
            bit.update(i + 1, nums.at(i));
        }
    }

    void update(int index, int val) {
        int delta = val - sumRange(index,index  );
        bit.update(index+1, delta);
    }

    int sumRange(int left, int right) {
        return bit.query(right+1) - bit.query(left);
    }
};

