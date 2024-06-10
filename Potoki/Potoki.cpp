#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }

        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        Sort(left);
        Sort(right);
        Merge(nums, left, right);
    }

private:
    void Merge(vector<int>& nums, vector<int>& left, vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            }
            else {
                nums[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            nums[k++] = left[i++];
        }

        while (j < right.size()) {
            nums[k++] = right[j++];
        }
    }
};

int main() {
    vector<int> nums(10);
    cout << "Enter 10 numbers: ";
    for (int& num : nums) {
        cin >> num;
    }

    MergeSort mergeSort;
    thread mergeSortThread([&mergeSort, &nums] { mergeSort.Sort(nums); });
    mergeSortThread.join();

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

