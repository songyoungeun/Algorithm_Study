import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 출력

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 걸그룹의 수
        int m = Integer.parseInt(st.nextToken()); // 맞출 문제 수
        Map<String,List<String>> girlGrp = new HashMap<>();
        Map<String, String> memberMap = new HashMap<>();

        while (n > 0) {
            String group = br.readLine();
            int num = Integer.parseInt(br.readLine());

            List<String> members = new ArrayList<>();

            for (int i = 0; i < num; i++) {
                String name = br.readLine(); // 멤버이름
                members.add(name);
                memberMap.put(name, group); // 멤버 -> 그룹 매핑
            }
            girlGrp.put(group, members);
            n--;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String str = br.readLine();
            int num = Integer.parseInt(br.readLine());
            // 0 멤버의 이름을 사전순으로 , 1 팀의 이름
            if (num == 0) {
                List<String> members = girlGrp.get(str);
                Collections.sort(members);
                for (String member : members) {
                    sb.append(member).append('\n');
                }
            }
            else {
                sb.append(memberMap.get(str)).append('\n');
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
