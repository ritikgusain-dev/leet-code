class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //we are comparing from the last bc nums1 me saare elements use nahi karne, only use first m elements , so if we start comparing from first then the elements may be over written in nums1 even before placing them in their correct place, so better compare from the last in both arrays
         int i = m - 1;        // Last valid element in nums1
        int j = n - 1;        // Last element in nums2
        int k = m + n - 1;    // Last position in nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements of nums2 if any
        //no loop for nums1 bc original changes are already being made in nums1, if nums1 ke pass kuch remaining bhi hoga compare karne ko toh vo waise bhi nums1 me apni sahi jagah par hoga since nums1 is already sorted
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};