import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력 n , m
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 출력

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 사이트 주소 수
        int m = Integer.parseInt(st.nextToken()); // 비번 찾는 주소 수

        Map<String,String> urlList = new HashMap<>(); // 주소

        // n 만큼 입력 받기 > 주소는 해시에 ? 비번은 리스트에
        for (int i = 1; i <= n; i++) {
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            String url = st1.nextToken();
            String pw = st1.nextToken();
            urlList.put(url, pw);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String findPw = br.readLine();
            sb.append(urlList.get(findPw)).append('\n');
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}