class Solution {
void tile(String tiles,HashSet<String>forcount,StringBuilder temp,HashSet<Integer>idx){
    if(temp.length()>tiles.length()){
        return ;
    }
    if(!temp.isEmpty()&&!forcount.contains(temp.toString())){
        forcount.add(temp.toString());
    }
    for(int i=0;i<tiles.length();i++){
        if(!idx.contains(i)){
            temp.append(tiles.charAt(i));
            idx.add(i);
            tile(tiles,forcount,temp,idx);
            temp.deleteCharAt(temp.length()-1);
            idx.remove(i);
        }
    }
}
    public int numTilePossibilities(String tiles) {
        HashSet<String>forcount=new HashSet<>();
        HashSet<Integer>idx=new HashSet<>();
        StringBuilder temp=new StringBuilder("");
        tile(tiles,forcount,temp,idx);
        return forcount.size();
    }
}