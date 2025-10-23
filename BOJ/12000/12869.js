const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const scv = input[1].split(" ").map(Number);

while (scv.length < 3) scv.push(0);

const attacks = [
  [9, 3, 1],
  [9, 1, 3],
  [3, 9, 1],
  [3, 1, 9],
  [1, 9, 3],
  [1, 3, 9],
];
const map = Array.from({ length: 64 }, () =>
  Array.from({ length: 64 }, () => Array.from({ length: 64 }, () => 0))
);
const vis = Array.from({ length: 64 }, () =>
  Array.from({ length: 64 }, () => Array.from({ length: 64 }, () => 0))
);

const dfs = (a, b, c) => {
  vis[a][b][c] = 1;
  const q = [];
  q.push([a, b, c]);

  while (q.length) {
    const [a, b, c] = q.shift();

    for (let i = 0; i < 6; i++) {
      let na = Math.max(0, a - attacks[i][0]);
      let nb = Math.max(0, b - attacks[i][1]);
      let nc = Math.max(0, c - attacks[i][2]);

      if (vis[na][nb][nc]) continue;
      vis[na][nb][nc] = vis[a][b][c] + 1;
      q.push([na, nb, nc]);
    }
  }

  return vis[0][0][0] - 1;
};

console.log(dfs(scv[0], scv[1], scv[2]));
