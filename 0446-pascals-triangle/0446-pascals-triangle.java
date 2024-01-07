public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if(numRows<1) return result;
        ArrayList<Integer> start = new ArrayList<Integer>();
        start.add(1);
        result.add(start);
        for(int i=2;i<=numRows;i++) {
            ArrayList<Integer> row = new ArrayList<Integer>();
            ArrayList<Integer> pre = result.get(i-2);
            row.add(pre.get(0));
            for(int j=1;j<i;j++) {
                row.add(pre.get(j-1) + pre.get(j));
            }        
            row.add(1);
            result.add(row);
        }
        return result;
    }
}