const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const a = Array.from({ length: 26 }).fill(0);
let ret = "";
input.shift();

input.forEach((v) => {
  if (v.length > 0) {
    a[v[0].charCodeAt() - "a".charCodeAt()]++;
  }
});

a.forEach((v, idx) => {
  if (v >= 5) {
    ret += String.fromCharCode(idx + "a".charCodeAt());
  }
});

console.log(ret.length === 0 ? "PREDAJA" : ret);
