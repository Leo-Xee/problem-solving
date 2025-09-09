const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input.shift();
const ret = [];

const go = (a, b, n) => {
  if (n === 1) {
    ret.push(`${a} ${b}`);
    return;
  }
  go(a, 6 - a - b, n - 1);
  ret.push(`${a} ${b}`);
  go(6 - a - b, b, n - 1);
};

console.log(2 ** N - 1);
go(1, 3, N);
console.log(ret.join("\n"));
