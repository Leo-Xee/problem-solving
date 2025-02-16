const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

const solution = () => {
  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  const [n, m] = input
    .shift()
    .split(" ")
    .map((v) => +v);

  const a = input.map((v) => v.split("").map((v) => +v));
  const visited = [...Array(n)].map(() => Array(m).fill(0));
  const q = [];

  visited[0][0] = 1;
  q.push([0, 0]);

  while (q.length) {
    const [y, x] = q.shift();
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] === 0) continue;
      if (visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push([ny, nx]);
    }
  }
  return visited[n - 1][m - 1];
};

console.log(solution());
