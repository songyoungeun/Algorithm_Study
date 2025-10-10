import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 출력

        // 재귀 > 비효 메모리초과나 시간초과 날수있
        String s = br.readLine(); // 문자열 조합 총 갯수

        Set<String> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                set.add(s.substring(i, j)); // 부분조합
            }
        }
        System.out.println(set.size());
    }
}