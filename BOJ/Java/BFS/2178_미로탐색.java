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
            String line = br.readLine();  // 한 줄 전체 읽기
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j) - '0';  // 문자 -> 숫자
            }
        }

        boolean[][] vis = new boolean[102][102]; // 방문여부
        int [][] dist = new int[n+1][m+1]; // 거리 배역
        int[] dx = {1, 0, -1, 0}; // 상하좌우
        int[] dy = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 || vis[i][j]) continue;
                Queue<int[]> q = new LinkedList<>();
                q.add(new int[]{i,j}); // 큐에 배열 0,0 넣고
                vis[i][j] = true;
                dist[i][j] = 1;
                while (!q.isEmpty()){
                    int[] cur = q.poll();
                    for (int dir = 0; dir < 4; dir++) {
                        int x = cur[0] + dx[dir];
                        int y = cur[1] + dy[dir];
                        if (x < 0 || y < 0 || x >= n || y >= m ) continue; // 범위밖일경우
                        if (dist[x][y] > 0 || map[x][y] == 0) continue; // 이미 방문 or 0일경우
                        dist[x][y]  = dist[cur[0]][cur[1]] + 1;
                        vis[x][y] = true;
                        q.add(new int[]{x, y});
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dist[n-1][m-1]);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}
