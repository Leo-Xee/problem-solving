const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let ret = 0;
const cnt = Array.from({ length: 26 }).fill(0);
const [a, b] = input.map((v) => v.split(""));

a.forEach((v) => {
  cnt[v.charCodeAt() - "a".charCodeAt()]++;
});

b.forEach((v) => {
  cnt[v.charCodeAt() - "a".charCodeAt()]--;
});

cnt.forEach((v) => {
  if (v !== 0) ret += Math.abs(v);
});

console.log(ret);
