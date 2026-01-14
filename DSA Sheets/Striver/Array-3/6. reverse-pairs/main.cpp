class Solution
{
public:
  int Merge(vector<int> &nums, int low, int mid, int high)
  {
    int total = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
      while (j <= high && nums[i] > 2LL * nums[j])
      {
        j++;
      }
      total += (j - (mid + 1)); // how many j's are covered where a[i] > 2*a[j]
    }

    vector<int> t;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {

      if (nums[left] <= nums[right])
      {
        t.push_back(nums[left++]);
      }
      else
      {
        t.push_back(nums[right++]);
      }
    }

    while (left <= mid)
    {
      t.push_back(nums[left++]);
    }
    while (right <= high)
    {
      t.push_back(nums[right++]);
    }

    for (int i = low; i <= high; i++)
    {
      nums[i] = t[i - low];
    }
    return total;
  }

  int MergeSort(vector<int> &nums, int low, int high)
  {

    if (low >= high)
      return 0;
    int mid = (low + high) / 2;
    int inv = MergeSort(nums, low, mid);
    inv += MergeSort(nums, mid + 1, high);
    inv += Merge(nums, low, mid, high);
    return inv;
  }

  int reversePairs(vector<int> &nums)
  {
    // ye merge sort wala hai.

    int n = nums.size();
    int ans = MergeSort(nums, 0, n - 1);

    return ans;
  }
};