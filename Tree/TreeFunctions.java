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
}
