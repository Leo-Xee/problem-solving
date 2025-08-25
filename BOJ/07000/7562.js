const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const dy = [-2, -1, 1, 2, 2, 1, -1, -2];
const dx = [1, 2, 2, 1, -1, -2, -2, -1];

let T = Number(input.shift());

while (T--) {
  const S = Number(input.shift());
  const a = Array(S)
    .fill()
    .map(() => Array(S).fill(-1));
  const [y, x] = input
    .shift()
    .split(" ")
    .map((v) => +v);
  const [yy, xx] = input
    .shift()
    .split(" ")
    .map((v) => +v);

  const q = [];
  q.push([y, x]);
  a[y][x] = 0;

  while (q.length) {
    const [y, x] = q.shift();
    for (let i = 0; i < 8; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= S || nx < 0 || nx >= S) continue;
      if (a[ny][nx] >= 0) continue;
      a[ny][nx] = a[y][x] + 1;
      q.push([ny, nx]);
    }
  }

  console.log(a[yy][xx]);
}
