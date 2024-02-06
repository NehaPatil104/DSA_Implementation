import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int M = scanner.nextInt();
        int N = scanner.nextInt();
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int result = minOperation(M, N, arr);
        System.out.println(result);

        scanner.close();
    }

    public static int minOperation(int M, int N, int[] arr) {
        int[] dp = new int[M + 1];

        for (int i = 1; i <= M; i++) {
            dp[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < N; i++) {
            for (int j = arr[i]; j <= M; j++) {
                dp[j] = Math.min(dp[j], dp[j - arr[i]] + 1);
            }
        }

        if (dp[M] == Integer.MAX_VALUE) {
            return -1;
        } else {
            return dp[M];
        }
    }
}
