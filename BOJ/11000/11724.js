const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, _] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const adj = Array.from({ length: N + 1 }, () => []);
const vis = Array.from({ length: N + 1 }, () => 0);
const edges = input.map((v) => v.split(" ").map((v) => +v));
let cnt = 0;

const dfs = (here) => {
  vis[here] = 1;
  for (let there of adj[here]) {
    if (!vis[there]) {
      dfs(there);
    }
  }
};

for (let [from, to] of edges) {
  adj[from].push(to);
  adj[to].push(from);
}

for (let i = 1; i <= N; i++) {
  if (!vis[i]) {
    dfs(i);
    cnt++;
  }
}

console.log(cnt);
