const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input;

let ret = 0;
let cnt = 0;

while (true) {
  ret++;
  if (ret.toString().includes("666")) cnt++;
  if (N === cnt) break;
}

console.log(ret);
