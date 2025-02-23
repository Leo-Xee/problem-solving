const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [n, k] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const max = 100_004;
const vis = Array.from({ length: max }).fill(-1);
const q = [];
let idx = 0;

const solution = (n, k) => {
  q.push(n);
  vis[n] = 0;

  while (q.length > idx && vis[k] === -1) {
    const here = q[idx++];

    for (let there of [here + 1, here - 1, here * 2]) {
      if (there < 0 || there > max) continue;
      if (vis[there] !== -1) continue;

      vis[there] = vis[here] + 1;
      q.push(there);
    }
  }

  return vis[k];
};

console.log(solution(n, k));
