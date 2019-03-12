public class TreeDriver {
	public static void main(String [] args) {
		TNode rootNode = TreeFunctions.createNode(1);
		rootNode.left = TreeFunctions.createNode(2);
		rootNode.right = TreeFunctions.createNode(3);
		TreeFunctions.dfsInorder(rootNode);
	}
}	
