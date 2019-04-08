public class TreeDriver {
	public static void main(String [] args) {
		TNode rootNode = TreeFunctions.createNode(8);
		rootNode.left = TreeFunctions.createNode(7);
		rootNode.right = TreeFunctions.createNode(9);
		//rootNode.left.left = TreeFunctions.createNode(6);
		rootNode.left.right = TreeFunctions.createNode(5);
		rootNode.left.right.right = TreeFunctions.createNode(4);
		//rootNode.right.right = TreeFunctions.createNode(10);
		rootNode.right.left = TreeFunctions.createNode(11);
		TreeFunctions.printDiaTraversal(rootNode);
	}
}	
