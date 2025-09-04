const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const map = input.map((row) => row.split(" ").map((v) => +v));
let vis = Array.from({ length: N }, () => Array.from({ length: M }).fill(0));

let cheeseeToMelt = [];
let hours = 0;
let cheeseeCnt = 0;

const bfs = (y, x) => {
  const q = [];
  vis[y][x] = 1;
  q.push([y, x]);
  while (q.length) {
    [y, x] = q.shift();
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (vis[ny][nx]) continue;
      if (map[ny][nx] === 1) {
        cheeseeToMelt.push([ny, nx]);
        vis[ny][nx] = 1;
        continue;
      }
      vis[ny][nx] = 1;
      q.push([ny, nx]);
    }
  }
};

while (true) {
  cheeseeToMelt = [];
  vis = Array.from({ length: N }, () => Array.from({ length: M }).fill(0));

  bfs(0, 0);
  cheeseeCnt = cheeseeToMelt.length;

  for (let [y, x] of cheeseeToMelt) {
    map[y][x] = 0;
  }

  let hasCheesee = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (map[i][j] === 1) {
        hasCheesee = 1;
      }
    }
  }
  hours++;
  if (!hasCheesee) break;
}
console.log(`${hours}\n${cheeseeCnt}`);
