public class Solution {
    public boolean repeatedSubstringPattern(String str) {
        for(int i = 0; i < str.length()/2; i++) {
            if(str.length() % ( i + 1) == 0) {
                boolean flag = true;
                String repeated = str.substring(0, i + 1);
                for(int j = i + 1; j < str.length(); j += i + 1) {
                    if(!repeated.equals(str.substring(j, j + i + 1))) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return true;
            }
        }
        return false;
    }
}