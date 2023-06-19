#include <vector>
#include <utility>

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> numIndexPairs;
        std::vector<int> counts(n, 0);

        for (int i = 0; i < n; ++i) {
            numIndexPairs.emplace_back(nums[i], i);
        }

        mergeSortAndCount(numIndexPairs, 0, n - 1, counts);
        return counts;
    }

private:
    void mergeSortAndCount(std::vector<std::pair<int, int>>& numIndexPairs, int left, int right, std::vector<int>& counts) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSortAndCount(numIndexPairs, left, mid, counts);
        mergeSortAndCount(numIndexPairs, mid + 1, right, counts);
        merge(numIndexPairs, left, mid, right, counts);
    }

    void merge(std::vector<std::pair<int, int>>& numIndexPairs, int left, int mid, int right, std::vector<int>& counts) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<std::pair<int, int>> leftArray(n1);
        std::vector<std::pair<int, int>> rightArray(n2);

        for (int i = 0; i < n1; ++i) {
            leftArray[i] = numIndexPairs[left + i];
        }
        for (int i = 0; i < n2; ++i) {
            rightArray[i] = numIndexPairs[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = left;
        int smallerCount = 0;

        while (i < n1 && j < n2) {
            if (leftArray[i].first <= rightArray[j].first) {
                counts[leftArray[i].second] += smallerCount;
                numIndexPairs[k++] = leftArray[i++];
            } else {
                smallerCount++;
                numIndexPairs[k++] = rightArray[j++];
            }
        }

        while (i < n1) {
            counts[leftArray[i].second] += smallerCount;
            numIndexPairs[k++] = leftArray[i++];
        }
        while (j < n2) {
            numIndexPairs[k++] = rightArray[j++];
        }
    }
};
