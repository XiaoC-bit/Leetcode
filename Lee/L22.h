#pragma once
#include <vector>
#include <string>
using namespace std;


/*
���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�



ʾ�� 1��

���룺n = 3
�����["((()))","(()())","(())()","()(())","()()()"]
ʾ�� 2��

���룺n = 1
�����["()"]


���룺n = 2
�����["()()","(())"]

��ʾ��

1 <= n <= 8

*/
class L22 {
public:
    vector<string> generateParenthesis(int n);
};