const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input[0].split(" ").map((v) => +v);

const num = [];
const ret = [];

const go = (depth) => {
  if (depth === M) {
    ret.push(num.join(" "));
    return;
  }

  const start = depth === 0 ? 1 : num[depth - 1] + 1;

  for (let i = start; i <= N; i++) {
    num[depth] = i;
    go(depth + 1);
  }
};

go(0);

ret.forEach((v) => console.log(v));
