const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let cnt = 0;
const t = Array.from({ length: 100 }).fill(0);
const [a, b, c] = input.shift().split(" ");

const solution = () => {
  input.forEach((v) => {
    const [from, to] = v.split(" ").map((v) => +v);

    for (let i = from; i < to; i++) {
      t[i]++;
    }
  });

  t.forEach((v) => {
    if (v === 1) cnt += v * a;
    if (v === 2) cnt += v * b;
    if (v === 3) cnt += v * c;
  });

  return cnt;
};

console.log(solution());
