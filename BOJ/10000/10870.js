const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();

const fibo = (n) => {
  if ((n === 0) | (n === 1)) return n;
  return fibo(n - 2) + fibo(n - 1);
};

console.log(fibo(n));
