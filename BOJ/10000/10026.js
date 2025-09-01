const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const N = +input.shift();
const a = input.map((v) => v.split(""));
let vis = Array.from({ length: N }, () => Array.from({ length: N }).fill(0));
let normal = 0;
let blind = 0;

const bfs = (y, x) => {
  const q = [];
  q.push([y, x]);
  vis[y][x] = 1;
  while (q.length) {
    [y, x] = q.shift();
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (vis[ny][nx] || a[y][x] !== a[ny][nx]) continue;
      q.push([ny, nx]);
      vis[ny][nx] = 1;
    }
  }
};

const startCount = () => {
  let cnt = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (!vis[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }
  return cnt;
};

normal = startCount();

vis = Array.from({ length: N }, () => Array.from({ length: N }).fill(0));

for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (a[i][j] === "R") a[i][j] = "G";
  }
}

blind = startCount();

console.log(`${normal} ${blind}`);
