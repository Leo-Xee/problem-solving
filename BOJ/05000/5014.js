const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [F, S, G, U, D] = input[0].split(" ").map((v) => +v);

const dist = Array.from({ length: F + 1 }, () => -1);
const q = [];

q.push(S);
dist[S] = 0;

while (q.length) {
  const current = q.shift();
  for (const next of [current + U, current - D]) {
    if (next > F || next <= 0 || dist[next] !== -1) continue;
    dist[next] = dist[current] + 1;
    q.push(next);
  }
}

console.log(dist[G] === -1 ? "use the stairs" : dist[G]);
