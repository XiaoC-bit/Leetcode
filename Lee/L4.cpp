#include "L4.h"



double L4::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}

	int m = nums1.size();
	int n = nums2.size();
	int left = 0, right = m;

	/**
     * ����numsRes���µĺϲ����飬��������Ҫ���ȥ�ϲ�����������㷨ֻ��Ѱ������������ĳ��λ�ã������ż��������ĳ����λ�ã���Ԫ�ض��ѡ�
	 * �˴�˼·�ǣ����������飬�ֱ���i����j���ֿ����������ߡ�����i+j = (m+n+1)/2 
	 * �����������鱾������������ֻҪ���� nums1[i-1] <= nums2[j]  &&  nums2[j-1] <= nums1[i]
	 * �Ϳ��Եõ�������ǰ (m+n+1)/2  ��Ԫ�ء�
	 * �õ������Ϣ�󣬾ͺ������ˡ�
	 * 
	 * ��һ���������Ϊ [0,i-1] �ܹ�i��
	 * �ڶ��������ұ�Ϊ [0,j-1] �ܹ�j��
	 * ���m+n��ż�������µ���ʽ  "+1"�Ĳ��֣������������á���λ������������ָ�ġ������� �� ���ұ���С����������Ԫ�ص�ƽ��ֵ
	 * ���m+n����������ô��߲��ֵ����Ԫ�أ�������λ��
	 */
	int totalLeft = (n + m + 1) / 2;



	while (left <= right) {

		//�Խ϶̵����飬���ж��ֲ��ҡ�����һ����������Ϸ�����ѧ֤����ʹ�ü����õ��±꼴�ɡ�
		/*
		*  ����A
		*  a[0] a[1] a[2]..... a[i-1] a[i] ..... a[m]
		*  ����B
		*  b[0] b[1] b[2]..... b[j-1] b[j] ..... b[n]
		* 
		*/
		int i = (left + right) / 2;
		int j = totalLeft - i;


		int ALeft, ARight, BLeft, BRight;

		/**
		 * �ο��Ϸ�������ʾ��ͼ������һЩcorner case ��Ҫ����
		 */
		ALeft = (i == 0) ? INT_MIN : nums1.at(i - 1);
		ARight = (i == m) ? INT_MAX : nums1.at(i);
		BLeft = (j == 0) ? INT_MIN : nums2.at(j - 1);
		BRight = (j == n) ? INT_MAX : nums2.at(j);


		if (ALeft <= BRight && BLeft <= ARight) {
			//�˴�������nums1[i-1] <= nums2[j]  &&  nums2[j-1] <= nums1[i]
			//����ҵ�������Ҫ�ķָ

			if ((m + n) % 2 == 1) {
				return std::max(ALeft, BLeft);
			}
			else {
				return (std::max(ALeft, BLeft) + std::min(ARight, BRight)) / 2.0;
			}
		}

		if (ALeft > BRight) {
			/**
			 * a[i-1] > b[j] ˵��i̫���ˡ�iҪ������ƶ�
			 * ��ô�������ұ߽�
			 */
			right = i - 1;
		}
		if (BLeft > ARight) {
			/**
			 * �˴�������һ����������߽�
			 */
			left = i + 1;
		}

	}
	return 0.0;
}
