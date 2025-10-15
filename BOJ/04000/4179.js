const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [R, C] = input.shift().split(" ").map(Number);

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const map = input.map((row) => row.split(""));
const visStart = Array(R)
  .fill()
  .map(() => Array(C).fill(0));
const visFire = Array(R)
  .fill()
  .map(() => Array(C).fill(0));
const qStart = [];
const qFire = [];

let possible = false;
let ret = null;

for (let i = 0; i < R; i++) {
  for (let j = 0; j < C; j++) {
    if (map[i][j] == "J") {
      visStart[i][j] = 1;
      qStart.push([i, j]);
    }
    if (map[i][j] == "F") {
      visFire[i][j] = 1;
      qFire.push([i, j]);
    }
  }
}

let idx = 0;

while (qFire.length) {
  const [y, x] = qFire.shift();

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if (map[ny][nx] === "#" || visFire[ny][nx]) continue;

    visFire[ny][nx] = visFire[y][x] + 1;
    qFire.push([ny, nx]);
  }
}

while (qStart.length && !possible) {
  const [y, x] = qStart.shift();

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
      possible = true;
      ret = visStart[y][x];
      break;
    }
    if (map[ny][nx] === "#" || visStart[ny][nx]) continue;
    if (visFire[ny][nx] && visStart[y][x] + 1 >= visFire[ny][nx]) continue;

    visStart[ny][nx] = visStart[y][x] + 1;
    qStart.push([ny, nx]);
  }
}

console.log(possible ? ret : "IMPOSSIBLE");
