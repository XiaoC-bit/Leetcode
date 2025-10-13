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

private:
    //��̬�滮�ⷨ
    vector<string> dp(int n);
    //ջ���ݷ�
    vector<string> stackbackTrace(int n);
    //�ݹ���ݷ�
    void recursizebackTrace(vector<string>& ans, string& cur, int open, int close, int n);

};