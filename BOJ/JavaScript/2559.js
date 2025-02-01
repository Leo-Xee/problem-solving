const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let ret = -10000004;
const psum = Array.from({ length: 100004 }).fill(0);

const [n, k] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const arr = input
  .shift()
  .split(" ")
  .map((v) => +v);

for (let i = 1; i <= n; i++) {
  psum[i] = psum[i - 1] + arr[i - 1];
}

for (let i = k; i <= n; i++) {
  ret = Math.max(ret, psum[i] - psum[i - k]);
}

console.log(ret);
