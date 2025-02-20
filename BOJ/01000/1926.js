const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [n, m] = input
  .shift()
  .split(" ")
  .map((v) => +v);
const a = input.map((v) => v.split(" ").map((v) => +v));
const visited = [...Array(n)].map(() => Array(m).fill(0));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let cnt = 0;
let max = 0;

const dfs = (y, x) => {
  visited[y][x] = 1;
  let size = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
    if (!a[ny][nx] || visited[ny][nx]) continue;
    size += dfs(ny, nx);
  }
  return size;
};

const solution = (n, m, a) => {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (a[i][j] === 1 && visited[i][j] === 0) {
        cnt++;
        max = Math.max(max, dfs(i, j));
      }
    }
  }

  return [cnt, max].join("\n");
};

console.log(solution(n, m, a));
