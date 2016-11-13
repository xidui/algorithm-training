public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
            
        int count = 0;
        for(int cookie : s) {
            if(count >= g.length)
                break;
            if(cookie >= g[count])
                count++;
        }
        return count;
    }
}