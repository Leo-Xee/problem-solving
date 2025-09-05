const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input.shift();
const nodes = input
  .shift()
  .split(" ")
  .map((v) => +v);
const target = +input.shift();

const adj = Array.from({ length: N }, () => []);
let root = null;

const dfs = (here) => {
  let ret = 0;
  let child = 0;
  for (let there of adj[here]) {
    if (there === target) continue;
    child++;
    ret += dfs(there);
  }
  if (child === 0) return 1;
  return ret;
};

for (let [idx, parent] of nodes.entries()) {
  if (parent == -1) {
    root = idx;
    continue;
  }
  adj[parent].push(idx);
}

console.log(target === root ? 0 : dfs(root));
