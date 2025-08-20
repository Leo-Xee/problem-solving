const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [M, N, _] = input
  .shift()
  .split(" ")
  .map((v) => +v);
const curs = input.map((v) => v.split(" ").map((v) => +v));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const a = [...Array(M)].map(() => Array(N).fill(0));
const vis = [...Array(M)].map(() => Array(N).fill(0));
const ret = [];

const bfs = (y, x) => {
  const q = [];
  vis[y][x] = 1;
  q.push([y, x]);

  let area = 0;

  while (q.length) {
    [y, x] = q.shift();
    area++;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
      if (!a[ny][nx] && !vis[ny][nx]) {
        vis[ny][nx] = 1;
        q.push([ny, nx]);
      }
    }
  }
  return area;
};

for (let cur of curs) {
  [x1, y1, x2, y2] = cur;

  for (let i = y1; i < y2; i++) {
    for (let j = x1; j < x2; j++) {
      a[i][j] = 1;
    }
  }
}

for (let i = 0; i < M; i++) {
  for (let j = 0; j < N; j++) {
    if (!a[i][j] && !vis[i][j]) {
      ret.push(bfs(i, j));
    }
  }
}

ret.sort((a, b) => a - b);
console.log(ret.length);
console.log(ret.join(" "));
