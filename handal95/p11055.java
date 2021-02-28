import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int[][] dp = new int[501][501];
	static int[] novel = new int[501];
	static int[] C = new int[501];
	static int[][] A = new int[501][501];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int test_case = Integer.parseInt(br.readLine());
		
		while(test_case-- > 0) {
			int chapter = Integer.parseInt(br.readLine());
			String[] c_size = br.readLine().split(" ");
			
			for(int i = 1; i <= chapter; i++) {
				novel[i] = Integer.parseInt(c_size[i-1]);
				C[i] = C[i-1] + novel[i];
			}
			
			for(int i = 1; i <= chapter; i++) {
				A[i-1][i] = i;
			}
			
			for(int i = 2; i <= chapter; i++) {
				for(int x = 0; x + i <= chapter; x++) {
					int y = x + i;
					dp[x][y] = Integer.MAX_VALUE;
					
					for(int k = A[x][y-1]; k <= A[x+1][y]; k++) {
						int min = dp[x][k] + dp[k][y] + C[y] - C[x];
						
						if(dp[x][y] > min) {
							dp[x][y] = min;
							A[x][y] = k;
						}
					}
				}
			}
			sb.append(dp[0][chapter] + "\n");
		}
		System.out.print(sb);
	}
}