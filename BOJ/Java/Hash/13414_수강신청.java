import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        // 입력 n , m
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 가능인원
        int m = Integer.parseInt(st.nextToken()); // 수강신청한 인원

        // accessOrder=true → 최근에 put된 순서 보장
        Map<String, Boolean> map = new LinkedHashMap<>(m, 0.75f, true);

        // m 만큼 입력 받기 > 해시에 넣기
        for (int i = 1; i <= m; i++) {
            String num = br.readLine();
            map.put(num, true);
        }
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (String key : map.keySet()) {
            sb.append(key).append("\n");
            count++;
            if (count == n) break;
        }

        System.out.print(sb);
    }
}
