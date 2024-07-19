class Solution {
    public int findPeakElement(int[] nums) {
        int start = 0;
        int end = nums.length - 1;
        while(start < end){

            int mid = start + (end - start) / 2;

            if(nums[mid] > nums[mid+1]){
                // you are in decreasing part of array
                // this may be the ans but look at the left
                // this is why end != mid - 1
                end = mid;
            }
            else {
                // you are in ascending part of the array
                start = mid + 1;// because we know that the mid+1 element is > mid hence we are ignoring the mid element
            }
            
        }
        // in the end start == end and pointing to the largest number because of the two checks above
// start and end are always trying to find the max element in the above two checks 
//hence when they are pointing to just one element that is the maximum one because that is what the checks say
        return start;// or u can return end as both are equal
    }
}