import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력 n , m
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 포켓몬 개수
        int m = Integer.parseInt(st.nextToken()); // 문제 개수

       String[] nameList = new String[n + 1];   // 번호 → 이름 (1부터 시작)
        Map<String,Integer> pocketmon = new HashMap<>();
        // n 만큼 입력 받기 > 해시에 넣기
        for (int i = 1; i <= n; i++) {
            String name = br.readLine();
            nameList[i] = name;
            pocketmon.put(name, i);
        }
        // 문제 입력 처리
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String q = br.readLine();
            if (Character.isDigit(q.charAt(0))) {
                // 숫자 → 이름
                int idx = Integer.parseInt(q);
                sb.append(nameList[idx]).append("\n");
            }
            else {
	   // 이름 → 번호
                sb.append( pocketmon.get(q)).append("\n");
            }
        }
       System.out.print(sb);


    }
}
