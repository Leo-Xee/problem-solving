const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const t = +input.shift();

let a, visited, m, n, k, x, y, ret;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const dfs = (y, x) => {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (a[ny][nx] === 0 || visited[ny][nx]) continue;
    dfs(ny, nx);
  }
};

for (let i = 0; i < t; i++) {
  ret = 0;
  [m, n, k] = input
    .shift()
    .split(" ")
    .map((v) => +v);

  a = [...Array(n)].map(() => Array(m).fill(0));
  visited = [...Array(n)].map(() => Array(m).fill(0));

  for (let j = 0; j < k; j++) {
    [x, y] = input
      .shift()
      .split(" ")
      .map((v) => +v);

    a[y][x] = 1;
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (a[i][j] === 1 && !visited[i][j]) {
        visited[i][j] = 1;
        dfs(i, j);
        ret++;
      }
    }
  }

  console.log(ret);
}
