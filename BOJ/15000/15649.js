const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const a = Array.from({ length: M }).fill(0);
const used = Array.from({ length: N + 1 }).fill(0);

const go = (depth) => {
  if (depth === M) {
    console.log(a.join(" "));
    return;
  }

  for (let i = 1; i <= N; i++) {
    if (!used[i]) {
      a[depth] = i;
      used[i] = 1;
      go(depth + 1);
      used[i] = 0;
    }
  }
};

go(0);
