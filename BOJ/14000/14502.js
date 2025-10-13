const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const [N, M] = input.shift().split(" ").map(Number);
const map = input.map((v) => v.split(" ").map(Number));
let vis = Array.from({ length: N }, () => Array.from({ length: M }, () => 0));

const noneList = [];
const virusList = [];
let ret = -Infinity;

const bfs = (y, x) => {
  const q = [];
  vis[y][x] = 1;
  q.push([y, x]);

  while (q.length) {
    const [y, x] = q.shift();

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if (map[ny][nx] === 1 || vis[ny][nx]) continue;

      vis[ny][nx] = 1;
      q.push([ny, nx]);
    }
  }
};

for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (map[i][j] === 0) noneList.push([i, j]);
    if (map[i][j] === 2) virusList.push([i, j]);
  }
}

for (let i = 0; i < noneList.length; i++) {
  for (let j = 0; j < i; j++) {
    for (let k = 0; k < j; k++) {
      map[noneList[i][0]][noneList[i][1]] = 1;
      map[noneList[j][0]][noneList[j][1]] = 1;
      map[noneList[k][0]][noneList[k][1]] = 1;

      vis = Array.from({ length: N }, () => Array.from({ length: M }, () => 0));

      for (let [y, x] of virusList) bfs(y, x);

      let cnt = 0;
      for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
          if (map[i][j] === 0 && !vis[i][j]) cnt++;
        }
      }

      ret = Math.max(ret, cnt);

      map[noneList[i][0]][noneList[i][1]] = 0;
      map[noneList[j][0]][noneList[j][1]] = 0;
      map[noneList[k][0]][noneList[k][1]] = 0;
    }
  }
}

console.log(ret);
