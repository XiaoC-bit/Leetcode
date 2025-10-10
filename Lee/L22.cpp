#include "L22.h"

#include <set>

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
vector<string> L22::generateParenthesis(int n) {
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
		std::set<std::string> diffSet;


		for (size_t t = 1; t <= j / 2; t++) {
			auto dict1 = dicts[t];
			auto dict2 = dicts[j-t];

			for (auto& s1 : dict1) {
				for (auto& s2 : dict2) {
					str = s1 + s2;
					if (diffSet.find(str) == diffSet.end()) {
						res.push_back(str);
						diffSet.insert(str);
					}

					str = s2 + s1;
					if (diffSet.find(str) == diffSet.end()) {
						res.push_back(str);
						diffSet.insert(str);
					}
				}
			}




		}


		for (size_t i = 0; i < dicts[j - 1].size(); i++) {
			str = "(" + dicts[j - 1].at(i) + ")";
			if (diffSet.find(str) == diffSet.end()) {
				res.push_back(str);
				diffSet.insert(str);
			}
		}

		dicts.push_back(res);
	}



	return dicts.at(n);
}
