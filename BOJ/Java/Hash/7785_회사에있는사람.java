import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        HashSet<String> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            String[] parts = line.split(" ");
            String name = parts[0];
            String action = parts[1];

            if (action.equals("enter")) {
                set.add(name);
            } else { // "leave"
                set.remove(name);
            }
        }

        // 결과를 내림차순(사전 역순)으로 출력하려면 리스트로 옮긴 뒤 정렬
        ArrayList<String> list = new ArrayList<>(set);
        Collections.sort(list, Collections.reverseOrder());

        StringBuilder sb = new StringBuilder();
        for (String name : list) {
            sb.append(name).append('\n');
        }
        System.out.print(sb.toString());
    }
}
