import java.util.*;

class Solution {
    public List<List<String>> partition(String s) {

        List<List<String>> ans = new ArrayList<>();
        List<String> arr = new ArrayList<>();
        part(s, arr, ans);
        return ans;
    }

    void part(String s, List<String> arr, List<List<String>> ans) {
        if (s.length() == 0) {
            ans.add(new ArrayList<>(arr));//deep copy aise bnti !!!!
            return;
        }

        for (int i = 1; i <= s.length(); i++) {
            String part = s.substring(0, i);
            if (isPal(part)) {
                arr.add(part);
                part(s.substring(i), arr, ans); 
                arr.remove(arr.size() - 1); 
            }
        }
    }

    boolean isPal(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}
