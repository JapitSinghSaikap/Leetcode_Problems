class Solution {
    public List<List<Integer>> combinationSum3(int k, int target) {

        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ls = new ArrayList<>();
        helper(ans, ls, 1, target, k, 0);
        return ans;
    }

    public void helper(List<List<Integer>> ans, List<Integer> ls, int curr, int target, int k, int sum){

        if(ls.size() == k){
            if(sum == target){
                ans.add(new ArrayList<>(ls));
            }
            return;
        }

        if(sum > target || curr > 9) return;

        ls.add(curr);
        helper(ans, ls, curr+1, target, k, sum + curr);
        ls.remove(ls.size() - 1);

        helper(ans, ls, curr+1, target, k, sum);
    }
}