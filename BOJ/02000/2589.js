const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const [H, W] = input.shift().split(" ").map(Number);
const map = input;
let vis = Array.from({ length: H }, () => Array(W).fill(0));
let max = 0;

const bfs = (y, x) => {
  vis = Array.from({ length: H }, () => Array(W).fill(0));

  const q = [];
  q.push([y, x]);
  vis[y][x] = 1;

  while (q.length) {
    const [y, x] = q.shift();

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if (map[ny][nx] === "W" || vis[ny][nx]) continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push([ny, nx]);
      max = Math.max(max, vis[ny][nx]);
    }
  }
};

for (let i = 0; i < H; i++) {
  for (let j = 0; j < W; j++) {
    if (map[i][j] === "L") {
      bfs(i, j);
    }
  }
}

console.log(max - 1);
