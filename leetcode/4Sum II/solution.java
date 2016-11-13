public class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int count = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int a = 0; a < A.length; a++) {
            for(int b = 0; b < B.length; b++) {
                int sum = 0 - A[a] - B[b];
                if(map.containsKey(sum))
                    map.put(sum, map.get(sum)+1);
                else
                    map.put(sum, 1);
            }
        }
        
        for(int c = 0; c < C.length; c++) {
            for(int d = 0; d < D.length; d++) {
                if(map.containsKey(C[c] + D[d]))
                    count += map.get(C[c] + D[d]);
            }
        }
        
        return count;
    }
}