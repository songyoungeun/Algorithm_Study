import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        // 입력 n , m
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine()); //테스트 수
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            Map<String, Integer> map = new HashMap<>();

            int m = Integer.parseInt(br.readLine()); //의상 수
            for (int i = 0; i < m; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String c = st.nextToken();   // 의상이름
                String type = st.nextToken(); // 의상종류
                map.put(type, map.getOrDefault(type, 0) + 1);
            }
            int result = 1;
            for (String key : map.keySet()) {
                result *= (map.get(key) + 1);
            }
            sb.append(result - 1).append('\n');
            n--;
        }


        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}