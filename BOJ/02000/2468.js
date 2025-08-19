const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();
const a = input.map((v) => v.split(" ").map((v) => +v));
let vis = [...Array(n)].map(() => Array(n).fill(0));
let ret = 1;

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const bfs = (y, x, d) => {
  vis[y][x] = 1;
  const q = [];
  q.push([y, x]);

  while (q.length) {
    const [y, x] = q.shift();

    for (let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (a[ny][nx] > d && !vis[ny][nx]) {
        vis[ny][nx] = 1;
        q.push([ny, nx]);
      }
    }
  }
};

for (let d = 0; d < 101; d++) {
  vis = [...Array(n)].map(() => Array(n).fill(0));
  let cnt = 0;

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (a[i][j] > d && !vis[i][j]) {
        bfs(i, j, d);
        cnt++;
      }
    }
  }
  ret = Math.max(ret, cnt);
}

console.log(ret);
