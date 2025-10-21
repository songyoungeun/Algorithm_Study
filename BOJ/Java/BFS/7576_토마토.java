import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[][] vis = new boolean[1002][1002]; // 방문여부
        int[] dx = {1, 0, -1, 0}; // 상하좌우
        int[] dy = {0, 1, 0, -1};

        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1)
                    q.add(new int[]{i,j});
            }
        }
        int[][] dist = new int[1002][1002];
        while (!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0]; int y = cur[1];
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue; // 범위밖일경우
                if (map[nx][ny] == 1 || map[nx][ny] == -1 || dist[nx][ny] > 0) continue; // 이미 방문 or 0일경우
                dist[nx][ny] = dist[x][y] + 1;
                map[nx][ny] = 1;
                q.add(new int[]{nx, ny});
            }
        }
        int flag = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if (map[i][j] == 0) flag = 1;
               else {
                   mx = Math.max(mx, dist[i][j]);
               }
            }
        }
        int day = flag == 1 ? -1 : mx;
        StringBuilder sb = new StringBuilder();
        sb.append(day);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}
