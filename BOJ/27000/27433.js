const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();

const fact = (n) => {
  if (n === 1) return n;
  return fact(n - 1) * n;
};

console.log(fact(n));
