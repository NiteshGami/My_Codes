/**
https://www.geeksforgeeks.org/sudoku-backtracking-7/
**/
import java.util.Arrays;
class SudokuSolver {
	private static final int MAX_ROW_COUNT = 16;
	private static final int MAX_COL_COUNT = 16;
	private static final int CUBE_WIDTH = 4;
	private static final int UNASSIGNED = 0;
	private static final int MAX_DIGIT = 16;

	
	public static int[][] solve(final int[][] inputMatrix){
		int[][] resultMatrix = null;
		
		if (!isValidMatrix(inputMatrix)) {
			return null;
		}
		
		resultMatrix = copyMatrix(inputMatrix);	
		
		if (putElements(resultMatrix)){
			return resultMatrix;
		} else {
			return null;
		}
	}
	
	private static boolean putElements(int[][] resultMatrix) {
		
		//Find unassigned value
		int currentRowIndex = -1;
		int currentColIndex = -1;
		for (int i = 0; i < MAX_ROW_COUNT; i++) {
			for (int j = 0; j < MAX_COL_COUNT; j++) {
				if (resultMatrix[i][j] == UNASSIGNED) {
					currentRowIndex = i;
					currentColIndex = j;
					break;
				}
			}
			//found unassigned value break outer loop
			if (currentRowIndex != -1)
			 break;
		}
		
		if (currentRowIndex == -1 && currentColIndex == -1) {
		    //No unassigned value found we are done
			return true;
		}
			
		for (int i = 0; i <= MAX_DIGIT; i++) {
			if (rowSafeCheck(currentRowIndex, i, resultMatrix)
				&& colSafeCheck(currentColIndex, i, resultMatrix)
				&& diagnalSafeCheck(currentRowIndex, currentColIndex, i, resultMatrix)
			) {
				resultMatrix[currentRowIndex][currentColIndex] = i;
				if (putElements(resultMatrix)) {
					//current placement is right break the loop.
					return true;
				} else {
					resultMatrix[currentRowIndex][currentColIndex] = UNASSIGNED;
				}
			}
		}
		
		return false;		
	}
	
	private static boolean rowSafeCheck(int rowIndex, int number, int[][] matrix) {
		if (!(rowIndex < MAX_ROW_COUNT))
			return false;
			
		boolean retVal = true;	
		for (int i = 0; i < MAX_COL_COUNT; i++) {
			if (matrix[rowIndex][i] == number)
				retVal = false;
		}
		return retVal;
	}
	
	private static boolean colSafeCheck(int colIndex, int number, int[][] matrix) {
		if (!(colIndex < MAX_COL_COUNT))
			return false;
			
		boolean retVal = true;	
		for (int i = 0; i < MAX_ROW_COUNT; i++) {
			if (matrix[i][colIndex] == number)
				retVal = false;
		}
		return retVal;
	}
	
	private static boolean diagnalSafeCheck(int rowIndex, int colIndex, int number, int[][] matrix) {
		if (!(colIndex < MAX_COL_COUNT && rowIndex < MAX_ROW_COUNT))
			return false;
			
		boolean retVal = true;
		int startRowIndex = (rowIndex/CUBE_WIDTH)*CUBE_WIDTH;
		int startColIndex = (colIndex/CUBE_WIDTH)*CUBE_WIDTH;
		for (int i = startRowIndex; i < (startRowIndex + CUBE_WIDTH) && i < MAX_ROW_COUNT ; i++) {
			for (int j = startColIndex; j <(startColIndex + CUBE_WIDTH) && j < MAX_COL_COUNT ; j++) {
			if (matrix[i][j] == number)
				retVal = false;
			}
		}
		return retVal;
	}
	
	private static boolean isValidMatrix(final int[][] inputMatrix) {
		return (inputMatrix != null && inputMatrix.length == MAX_ROW_COUNT && inputMatrix[0].length == MAX_COL_COUNT);
	}
	
	private static int[][] copyMatrix(final int[][] inputMatrix) {
		int[][] resultMatrix = new int[inputMatrix.length][];
		for (int i = 0; i < inputMatrix.length; i++) {
			resultMatrix[i] = Arrays.copyOf(inputMatrix[i], inputMatrix[i].length);
		}
		return resultMatrix;
	}
	
	public static void printMatrix(final int[][] matrix) {
		if (matrix == null)
			return;
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[i].length; j++) {
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println("\n");
		}
	}
	
	public static void main(String[] args) {
		int[][] inputMatrix = new int[][] { { 0, 0, 13, 11, 16, 0, 12, 6, 3, 0, 15, 0, 0, 0, 0, 0},
         { 1, 0, 0, 0, 7, 0, 0, 0, 12, 0, 9, 16, 6, 0, 0, 4},
         { 0, 12, 0, 0, 14, 0, 0, 0, 0, 5, 8, 0, 0, 1, 0, 0},
         { 16, 0, 0, 2, 0, 0, 0, 0, 14, 6, 13, 0, 9, 11, 0, 12},
         { 0, 0, 0, 0, 0, 13, 2, 4, 0, 0, 3, 0, 0, 6, 0, 0},
         { 0, 0, 9, 0, 0, 15, 0, 0, 16, 13, 0, 14, 11, 4, 7, 0},
         { 0, 13, 14, 3, 0, 16, 0, 0, 11, 4, 5, 0, 15, 2, 0, 0},
         { 0, 0, 0, 0, 8, 14, 0, 12, 0, 9, 1, 10, 5, 0, 0, 0},
	     { 0, 11, 0, 5, 0, 0, 15, 10, 0, 0, 4, 0, 0, 0, 6, 0},
         { 0, 0, 1, 4, 11, 0, 0, 9, 0, 16, 0, 0, 0, 0, 15, 14},
         { 0, 16, 0, 13, 0, 0, 8, 0, 15, 0, 0, 9, 3, 0, 0, 2},
         { 0, 3, 0, 10, 1, 0, 0, 0, 8, 12, 0, 13, 0, 0, 0, 7},
         { 0, 0, 0, 0, 2, 6, 0, 0, 0, 8, 11, 1, 0, 0, 9, 0},
         { 5, 0, 0, 6, 0, 12, 7, 1, 9, 0, 0, 15, 16, 14, 4, 0},
         { 0, 0, 0, 0, 0, 4, 0, 0, 6, 0, 0, 0, 10, 3, 0, 0},
		{ 7, 8, 2, 9, 0, 0, 0, 11, 13, 0, 0, 0, 0, 12, 5, 6}};
		System.out.println("*****Input Sudoku *****");
		SudokuSolver.printMatrix(inputMatrix);
		int[][] resultMatrix = SudokuSolver.solve(inputMatrix);
		System.out.println("*****Resultant Sudoku *****");
		SudokuSolver.printMatrix(resultMatrix);		
	}
}
