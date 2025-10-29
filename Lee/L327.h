#pragma once
#include "common.h"


class  BIT
{
private:
    vector<int64_t>trees;
    size_t n_;
public:
    BIT(size_t n) :n_(n), trees(n + 1, 0) {
    };
    ~BIT() {
    };

    static int lowBit(int x) {
        return x & (-x);
    }

    void update(int x, int64_t delta) {
        while (x <= n_) {
            trees[x] += delta;
            x += lowBit(x);
        }
    }

    int64_t query(int x) {
        int64_t count = 0;
        while (x > 0) {
            count += trees[x];
            x -= lowBit(x);
        }
        return count;
    }
};

class L327
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {};
        for (int v : nums) {
            sum += v;
            preSum.push_back(sum);
        }

        /**
         * �����
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
            Ҳ������ɢ����������x - lower��x - upper��������ɢ������ռ��λ�ã����ܽ���ͳ�ơ�
            ��ʹ������preSum��ֻ��Ϊ��ͳ��
         */
        set<long long> allNumbers;
        for (long long x : preSum) {
            allNumbers.insert(x);
            allNumbers.insert(x - lower);
            allNumbers.insert(x - upper);
        }
        // ���ù�ϣ�������ɢ��
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers) {
            values[x] = idx;
            idx++;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < preSum.size(); i++) {
            int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
            ret += bit.query(right + 1) - bit.query(left);
            //ֻ����preSum��Ԫ�ء�
            bit.update(values[preSum[i]] + 1, 1);
        }
        return ret;
    }
};

