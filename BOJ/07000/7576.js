const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [m, n] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const a = input.map((v) => v.split(" ").map((v) => +v));
const vis = [...Array(n)].map((v) => Array(m).fill(0));

const solution = (m, n, a) => {
  const q = [];
  let idx = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (a[i][j] === 1) {
        q.push([i, j]);
      }
      if (a[i][j] === 0) {
        vis[i][j] = -1;
      }
    }
  }

  while (q.length > idx) {
    const [y, x] = q[idx++];

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (a[ny][nx] === -1 || vis[ny][nx] >= 0) continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push([ny, nx]);
    }
  }

  let max = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (vis[i][j] === -1) {
        return -1;
      }
      max = Math.max(max, vis[i][j]);
    }
  }

  return max;
};

console.log(solution(m, n, a));
