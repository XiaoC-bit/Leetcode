#include "L22.h"

#include <set>
#include <stack>

/*
* ʹ�ö�̬�滮
* 1.F(0) �� F��1�����Զ��׼��ģ������ó�ʼ��
* 2.ͨ���ƶϣ��õ���ʽ  F(n) = "(" + F(p)  + ")" + F(q)
*	����p+q = n-1 .
*	֤����ʽ�������ѵ�����ô֤�����µ�ʽ����ʱ��p��Ȼ����m && q��Ȼ����n������޷�֤������ô����Ҫʹ��set�����˽�����������ʱ�临�Ӷ�
*	"(" + F(p)  + ")" + F(q) = "(" + F(m)  + ")" + F(n)
*	a.��ʽ���������ߣ��Ƕ����ģ�Ҳ���ǺϷ������ű��ʽ��
*	b.F(q)�����ǿգ��յ���������׵õ�F��n��Ҳ����Ϊ�ա���ôF��p) = F(m)
*	c.F(q)�ǿգ����ڼӺ����߱����Ƕ����ı��ʽ��Ҳ���׵õ�����Ҫ�Ľ����
*	
*/
//��̬�滮�ⷨ
vector<string> L22::dp(int n) {
	std::vector<std::vector<std::string>> dicts;

	vector<string> res;
	res.push_back("");
	dicts.push_back(res);


	res.clear();
	res.push_back("()");
	dicts.push_back(res);
	std::string str;
	for (int j = 2; j <= n; j++) {
		res.clear();
		for (size_t t = 0; t < j; t++) {
			auto dict1 = dicts[t];
			auto dict2 = dicts[j - t - 1];

			for (auto& s1 : dict1) {
				for (auto& s2 : dict2) {
					str = "(" + s1 + ")" + s2;
					res.push_back(str);
				}
			}
		}

		dicts.push_back(res);
	}



	return dicts.at(n);
}


/**
 * ջ���ݷ���������õ�.�������˺������õ�ջ����
 * 
 * \param n
 * \return 
 */
vector<string> L22::stackbackTrace(int n) {



	struct Step {
		std::string str;
		int open;
		int close;

		Step() {
			str = "";
			open = close = 0;
		}
	};

	vector<string> res;

	if (n == 0) {
		res.push_back("");
		return res;
	}

	stack<Step> st;
	Step step;
	step.open = 1;
	step.str = "(";
	st.push(step);

	while (st.size()) {
		auto step = st.top();
		st.pop();

		if (step.open < n) {
			auto newStep = step;
			newStep.open++;
			newStep.str += "(";
			st.push(newStep);
		}

		if (step.open > step.close) {
			auto newStep = step;
			newStep.close++;
			newStep.str += ")";
			if (newStep.str.size() == n * 2) {
				res.push_back(newStep.str);
			}
			else {
				st.push(newStep);
			}
		}		
	}


	return res;
}


/**
 * �ݹ���ݷ�������û��ջ���ݺã������׶��Ը���.
 * 
 * \param ans
 * \param cur
 * \param open
 * \param close
 * \param n
 */
void L22::recursizebackTrace(vector<string>& ans, string& cur, int open, int close, int n) {
	if (cur.size() == n * 2) {
		ans.push_back(cur);
		return;
	}
	if (open < n) {
		cur.push_back('(');
		recursizebackTrace(ans, cur, open + 1, close, n);
		cur.pop_back();
	}
	if (close < open) {
		cur.push_back(')');
		recursizebackTrace(ans, cur, open, close + 1, n);
		cur.pop_back();
	}
}


vector<string> L22::generateParenthesis(int n) {

	
	vector<string> result;
	string current;
	recursizebackTrace(result, current, 0, 0, n);
	return result;


	return stackbackTrace(n);

	return dp(n);
}
