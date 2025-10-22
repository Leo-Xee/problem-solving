const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [, ...arr] = input.map((v) => v.split(" ").map((v) => +v));

arr.sort((a, b) => {
  if (a[1] !== b[1]) return a[1] - b[1];
  return a[0] - b[0];
});

console.log(arr.map((v) => v.join(" ")).join("\n"));
