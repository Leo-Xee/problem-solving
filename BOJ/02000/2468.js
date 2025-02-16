const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let n = +input.shift();
let a = input.map((v) => v.split(" ").map((v) => +v));
let visited = [...Array(n)].map(() => Array(n).fill(0));

let ret = 1;
let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

const dfs = (y, x, d) => {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    let ny = y + dy[i];
    let nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if (visited[ny][nx] || a[ny][nx] <= d) continue;
    dfs(ny, nx, d);
  }
};

for (let d = 1; d < 101; d++) {
  let cnt = 0;
  visited = [...Array(n)].map(() => Array(n).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!visited[i][j] && a[i][j] > d) {
        dfs(i, j, d);
        cnt++;
      }
    }
  }

  ret = Math.max(cnt, ret);
}

console.log(ret);
