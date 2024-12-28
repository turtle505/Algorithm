#include <bits/stdc++.h>
using namespace std;

int n;
int board[10][10];  // 체스판 정보
bool diag1[20], diag2[20];  // 대각선 점유 상태
int maxBishops[2];  // 검은 칸과 흰 칸에서 놓을 수 있는 비숍 최대 개수

// 백트래킹 함수
void solve(int idx, int bishops, bool isBlack) {
    if (idx >= n * n) {
        maxBishops[isBlack] = max(maxBishops[isBlack], bishops);
        return;
    }

    // 현재 칸의 좌표
    int row = idx / n;
    int col = idx % n;

    // 현재 칸이 속한 대각선
    int d1 = row + col;
    int d2 = row - col + n - 1;

    // 현재 칸이 주어진 색상인지 확인
    if ((row + col) % 2 == isBlack && board[row][col] == 1 && !diag1[d1] && !diag2[d2]) {
        // 비숍을 현재 칸에 놓는 경우
        diag1[d1] = diag2[d2] = true;
        solve(idx + 1, bishops + 1, isBlack);
        diag1[d1] = diag2[d2] = false;
    }

    // 비숍을 놓지 않는 경우
    solve(idx + 1, bishops, isBlack);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 검은 칸과 흰 칸에서 각각 최대 비숍 개수를 계산
    solve(0, 0, 0);  // 검은 칸
    solve(0, 0, 1);  // 흰 칸

    // 결과 출력
    cout << maxBishops[0] + maxBishops[1] << '\n';
    return 0;
}
