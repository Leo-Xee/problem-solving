const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, L, R] = input.shift().split(" ").map(Number);
const map = input.map((v) => v.split(" ").map(Number));
let vis = Array.from({ length: N }, () => Array(N).fill(0));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let countries = [];
let sum = 0;
let ret = 0;

const bfs = (y, x) => {
  const q = [];
  q.push([y, x]);
  vis[y][x] = 1;

  countries.push([y, x]);
  sum += map[y][x];

  while (q.length) {
    const [y, x] = q.shift();

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
      if (
        Math.abs(map[y][x] - map[ny][nx]) < L ||
        Math.abs(map[y][x] - map[ny][nx]) > R
      )
        continue;
      if (vis[ny][nx]) continue;

      vis[ny][nx] = 1;
      q.push([ny, nx]);

      countries.push([ny, nx]);
      sum += map[ny][nx];
    }
  }
};

while (true) {
  let isMoved = false;
  vis = Array.from({ length: N }, () => Array(N).fill(0));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (!vis[i][j]) {
        countries = [];
        sum = 0;
        bfs(i, j);

        if (countries.length > 1) {
          isMoved = true;
          for (let c of countries) {
            map[c[0]][c[1]] = Math.floor(sum / countries.length);
          }
        }
      }
    }
  }

  if (!isMoved) break;
  ret++;
}

console.log(ret);
