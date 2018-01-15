

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int num = nums1.size() + nums2.size();
		if(num == 0) return 0;
		if(num%2){
			return find(nums1, 0, nums2, 0, (num+1)/2);

		} else {
			return (find(nums1, 0, nums2, 0, num/2) + find(nums1, 0, nums2, 0, num/2+1) )/2.0;
		}
	}

	int find(vector<int>& nums1, int st1, vector<int> &nums2, int st2, int k)
	{
		int ed1 = nums1.size() - 1;
		int ed2 = nums2.size() - 1;
		if(ed1<st1)return nums2[st2+k-1];
		if(ed2<st2)return nums1[st1+k-1];
		if(k==1){
			int k1 = nums1[st1];
			int k2 = nums2[st2];
			return k1<k2?k1:k2;
		}

		int m1 = k/2;
		if(m1>ed1-st1+1){
			m1 = ed1-st1+1;
		}
		int m2 = k - m1;
		if(m2>ed2-st2+1)
		{
			m2 = ed2-st2+1;
			m1 = k - m2;
		}

		int v1 = nums1[st1+m1-1];
		int v2 = nums2[st2+m2-1];
		if(v1<v2){
			return find(nums1, st1+m1, nums2, st2, k-m1);
		} else {
			return find(nums1, st1, nums2, st2+m2, k-m2);
		}	
	}
};
