class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(nums[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) 
  {
    nums[j++] = x;
  }
  for (int i = 0; i < k; i++) {
    cout << nums[i] << " ";
  }
  for(int j=set.size()+1;j<=n;j++){
      cout<<"_"<<" ";
  }

  return k;
        
        
    }
};



// int removeDuplicates(int arr[], int n) 
// {
//   set < int > set;
//   for (int i = 0; i < n; i++) {
//     set.insert(arr[i]);
//   }
//   int k = set.size();
//   int j = 0;
//   for (int x: set) 
//   {
//     arr[j++] = x;
//   }
//   for (int i = 0; i < k; i++) {
//     cout << arr[i] << " ";
//   }
//   for(int j=set.size()+1;j<=n;j++){
//       cout<<"_"<<" ";
//   }

//   return k;
// }