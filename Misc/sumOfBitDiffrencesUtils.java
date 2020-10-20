class sumOfBitDiffrencesUtils {
	private static int calculate(int inputArray[]) {
		int arrayLength = (inputArray != null) ? inputArray.length : 0;
		int result = 0;
		
		//invalid case length 0
		if (arrayLength == 0)
			return -1;
		//base case length 1
		if (arrayLength == 1) 
			return 0;
		//core logic
		for (int i = 0; i < 32; i++) {
		    int count = 0;
			for (int j = 0; j < arrayLength; j++) {
			   if ((inputArray[j] & (1 << i)) != 0)
				count++;
			}
			result += count * (arrayLength - count)*2;
		}
		return result;
	}
	public static void main(String args[]) {
		int []input = {1, 2};
		System.out.println(sumOfBitDiffrencesUtils.calculate(input));
	}
}