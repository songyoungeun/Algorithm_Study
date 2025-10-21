import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        boolean[][] vis = new boolean[502][502]; // 방문여부

        int[] dx = {1, 0, -1, 0}; // 상하좌우
        int[] dy = {0, 1, 0, -1};

        int count = 0; // 그림수
        int mx = 0; // 최대 넓이
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 || vis[i][j]) continue;
                count++;
                Queue<int[]> q = new LinkedList<>();
                q.add(new int[]{i,j}); // 큐에 배열 0,0 넣고
                vis[i][j] = true;
                int area = 0; // 그림넓이
                while (!q.isEmpty()){
                    area ++;
                    int[] cur = q.poll();
                    for (int dir = 0; dir < 4; dir++) {
                        int x = cur[0] + dx[dir];
                        int y = cur[1] + dy[dir];
                        if (x < 0 || y < 0 || x >= n || y >= m ) continue; // 범위밖일경우
                        if (vis[x][y] || map[x][y] == 0) continue; // 이미 방문 or 0일경우
                        vis[x][y] = true;
                        q.add(new int[]{x, y});
                    }
                }
                // i, j 시작점으로 하는 bfs 종료
                mx = Math.max(mx, area);
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(count).append('\n').append(mx);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}