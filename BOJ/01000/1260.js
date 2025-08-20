const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, _, V] = input
  .shift()
  .split(" ")
  .map((v) => +v);
const edges = input.map((v) => v.split(" ").map((v) => +v));
const adj = [...Array(N + 1)].map(() => []);
let vis = [...Array(N + 1)].fill(0);
const ret1 = [];
const ret2 = [];

const dfs = (here) => {
  if (vis[here]) return;
  vis[here] = 1;
  ret1.push(here);
  for (let there of adj[here]) {
    if (vis[there]) continue;
    dfs(there);
  }
};

const bfs = (here) => {
  const q = [];
  vis[here] = 1;
  q.push(here);
  while (q.length) {
    const here = q.shift();
    ret2.push(here);
    for (let there of adj[here]) {
      if (vis[there]) continue;
      vis[there] = 1;
      q.push(there);
    }
  }
};

for (let [from, to] of edges) {
  adj[from].push(to);
  adj[to].push(from);
}

// 비교함수를 제공하지 않으면, 배열의 모든 요소를 문자열로 변환한 다음 UTF-16 코드 단위 순서로 정렬한다.
for (let it of adj) it.sort((a, b) => a - b);

dfs(V);
vis = [...Array(N + 1)].fill(0);
bfs(V);

console.log(ret1.join(" "));
console.log(ret2.join(" "));
