const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let T = +input.shift();

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const ret = [];

while (T--) {
  const [W, H] = input
    .shift()
    .split(" ")
    .map((v) => +v);

  let a = Array.from({ length: H }).map(() => input.shift().split(""));
  let visF = Array.from({ length: H }, () => Array.from({ length: W }).fill(0));
  let visS = Array.from({ length: H }, () => Array.from({ length: W }).fill(0));

  let success = false;
  const qF = [];
  const qS = [];

  for (let i = 0; i < H; i++) {
    for (let j = 0; j < W; j++) {
      if (a[i][j] === "#") {
        a[i][j] = 0;
      } else {
        if (a[i][j] === "*") {
          qF.push([i, j]);
          visF[i][j] = 1;
        }
        if (a[i][j] === "@") {
          qS.push([i, j]);
          visS[i][j] = 1;
        }
        a[i][j] = 1;
      }
    }
  }

  let head = 0;
  while (head < qF.length) {
    const [y, x] = qF[head++];
    for (let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
      if (!a[ny][nx]) continue;
      if (visF[ny][nx]) continue;
      visF[ny][nx] = visF[y][x] + 1;
      qF.push([ny, nx]);
    }
  }

  head = 0;
  while (head < qS.length && !success) {
    const [y, x] = qS[head++];
    for (let i = 0; i < 4; i++) {
      let ny = y + dy[i];
      let nx = x + dx[i];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
        ret.push(visS[y][x]);
        success = true;
        break;
      }
      if (!a[ny][nx]) continue;
      if (visS[ny][nx]) continue;
      if (visF[ny][nx] && visF[ny][nx] <= visS[y][x] + 1) continue;
      visS[ny][nx] = visS[y][x] + 1;
      qS.push([ny, nx]);
    }
  }
  if (!success) ret.push("IMPOSSIBLE");
}

console.log(ret.join("\n"));
