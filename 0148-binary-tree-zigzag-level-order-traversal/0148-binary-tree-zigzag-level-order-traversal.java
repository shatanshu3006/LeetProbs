/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return null;
		
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		ArrayList<TreeNode> stack = new ArrayList<>();
		stack.add(root);
		int currentLevel = 1;
		int nextLevel = 0;
		boolean reverse = false;
		ArrayList<Integer> row = new ArrayList<>();
		while(stack.size() > 0) {
			TreeNode node = stack.remove(0);
			currentLevel--;
			if (!reverse) {
				row.add(node.val);
			} else {
				row.add(0, node.val);
			}
			if (node.left != null) {
				stack.add(node.left);
				nextLevel++;
			}
			if (node.right != null) {
				stack.add(node.right);
				nextLevel++;
			}
			if (currentLevel == 0) {
				currentLevel = nextLevel;
				nextLevel = 0;
				result.add(row);
				row = new ArrayList<>();
			}
		}
		return result;
    }
}