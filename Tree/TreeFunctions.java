import java.util.*;
public class TreeFunctions {
	public static TNode createNode (int dummyData){
		TNode newNode = new TNode();
		newNode.data = dummyData;
		newNode.left = null;
		newNode.right = null;			
		return newNode;
	}
	public static void dfsInorder (TNode root) {
		if (root == null)
			return;
		dfsInorder(root.left);
		System.out.println(root.data + "--->");
		dfsInorder(root.right);
	}
	public static void treeDiaTraversal(TNode root) {
		Map<Integer, List<Integer>> nodemap = new HashMap<Integer, List<Integer>>();
		treeDiaTraversalUtil(root, 0, nodemap);
		for(Map.Entry<Integer, List<Integer>> entrySet: nodemap.entrySet()) {
			List<Integer> nodelist = entrySet.getValue();
			System.out.println(nodelist);
		}	
	}
	private static void treeDiaTraversalUtil(TNode root, int level, Map<Integer, List<Integer>> nodemap) {
		if (root != null) {
			List nodelist = nodemap.get(level);
			if (nodelist == null) {
				nodelist = new ArrayList<Integer>();
			}
			nodelist.add(root.data);
			nodemap.put(level, nodelist);
			treeDiaTraversalUtil(root.left, level+1, nodemap);
			treeDiaTraversalUtil(root.right, level, nodemap);
		}
	}
	private static int maxLeftDepthUtil(TNode root, int isLeft) {
		if (root != null) {
			int leftDepth = maxLeftDepthUtil(root.left, 1);
			int rightDepth = maxLeftDepthUtil(root.right, 0);
			int finalDepth = (leftDepth > rightDepth) ? leftDepth : rightDepth;
			if (isLeft == 1) {
				return finalDepth + 1;
			} else {
				return finalDepth;
			}
		}
		return 0;
	}
	private static int maxLeftDepth(TNode root) {
		if (root != null) {
			int leftDepth = maxLeftDepthUtil(root.left, 1);
			int rightDepth = maxLeftDepthUtil(root.right, 0);
			return (leftDepth > rightDepth) ? (leftDepth + 1)  : (rightDepth + 1);
		}
		return 0;
	}
	private static void printGivenLevel(TNode root, int level, int desiredLevel) {
		if (root != null) {
			if (level == desiredLevel) {
				System.out.print(root.data + "--->");
				printGivenLevel(root.right, level, desiredLevel);
			} else {
				printGivenLevel(root.left, level+1, desiredLevel);
				printGivenLevel(root.right, level, desiredLevel);
			}
		}
	}
	public static void printDiaTraversal(TNode root) {
		int leftDepth = maxLeftDepth(root);
		for (int i = 0; i < leftDepth; i++) {
			System.out.print("level "+i+":");
			printGivenLevel(root, 0, i);
			System.out.println();
		}
	}		
}
