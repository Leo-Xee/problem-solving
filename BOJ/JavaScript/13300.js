const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let ret = 0;
const men = Array.from({ length: 7 }).fill(0);
const women = Array.from({ length: 7 }).fill(0);
const [n, k] = input
  .shift()
  .split(" ")
  .map((v) => +v);

input.forEach((v) => {
  const [s, g] = v.split(" ").map((v) => +v);

  if (s === 0) women[g]++;
  if (s === 1) men[g]++;
});

men.forEach((v) => {
  ret += Math.floor(v / k);
  if (v % k) ret++;
});

women.forEach((v) => {
  ret += Math.floor(v / k);
  if (v % k) ret++;
});

console.log(ret);
