const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, _] = input
  .shift()
  .split(" ")
  .map((v) => +v);
const edges = input.map((v) => v.split(" ").map((v) => +v));

let adj = [...Array.from({ length: N + 1 })].map(() => []);
let vis = Array.from({ length: N + 1 }, () => 0);

let counts = Array.from({ length: N + 1 }, () => 0);
let max = 0;
let ret = [];

// 재귀 호출보다 반복문 기반이 오버헤드가 적음
const dfs = (here) => {
  const stack = [here];
  vis[here] = 1;
  let cnt = 1;

  while (stack.length > 0) {
    here = stack.pop();

    // for ... of 문 오버헤드가 적음
    for (let i = 0; i < adj[here].length; i++) {
      const there = adj[here][i];
      if (!vis[there]) {
        vis[there] = 1;
        stack.push(there);
        cnt++;
      }
    }
  }
  return cnt;
};

for (let [from, to] of edges) {
  adj[to].push(from);
}

for (let i = 1; i <= N; i++) {
  vis.fill(0); // 배열을 생성해서 초기화 하는 것볻다 오버헤드가 적음
  counts[i] = dfs(i);
  max = Math.max(max, counts[i]);
}

for (let i = 1; i <= N; i++) {
  if (counts[i] === max) {
    ret.push(i);
  }
}

console.log(ret.join(" "));
