public class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0)
            return s;
        int rear = s.length() - 1;
        //do not forget to check index!!
        while(rear >= 0 && s.charAt(rear) == ' ')
            rear--;
        if (rear < 0)
            return "";
        StringBuilder temp = new StringBuilder();
        StringBuilder str = new StringBuilder();
        int substrLen = 0, startIndex = rear;
        for(int i = rear; i>=0; i--) {
            if (s.charAt(i) != ' ') {
                substrLen ++;
            } else {
                if (substrLen != 0) {
                    str.append(s.substring(startIndex-substrLen+1,substrLen));
                    str.append(' ');
                    substrLen = 0;
                }
                startIndex = i - 1;
            }
        }
        if (substrLen != 0) {
            str.append(s.substring(0,substrLen));
            return str.toString();
        }
        else {
            if (str.length() == 0)
                return "";
            str.deleteCharAt(str.length()-1);
            return str.toString();
        }
    }
}