func twoSum(nums []int, target int) []int {
    hash := make(map[int]int) 
    var ans[]int; 
    for i:=0; i<len(nums);i++{
        complement := target - nums[i]
        _,exist := hash[complement]
        if exist{
            ans = append(ans,i,hash[complement])
        }
        hash[nums[i]] = i
    }
    return ans
}
