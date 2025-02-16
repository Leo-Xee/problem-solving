const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim();

const a = Array.from({ length: 26 }).fill(0);

const solution = (input) => {
  input.split("").forEach((v) => a[v.charCodeAt() - 97]++);
  return a.join(" ");
};

console.log(solution(input));
