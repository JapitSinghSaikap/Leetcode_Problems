class Solution {
    public boolean wordPattern(String pattern, String s) {
        //pattern "a b b a"
        String[] words = s.split(" ");//[dog,cat,cat,fish]
        if (words.length != pattern.length()) return false;

        HashMap<Character,String> mp = new HashMap<>();//
        HashSet<String> used = new HashSet<>();

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String w = words[i];

            if (mp.containsKey(c)) {
                if (!mp.get(c).equals(w)) return false;
            } else {
                if (used.contains(w)) return false;
                mp.put(c, w);//add the pair found
                used.add(w);//add the word used
            }
        }
        return true;
    }
}