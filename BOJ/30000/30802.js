const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input.shift();
const shirts = input
  .shift()
  .split(" ")
  .map((v) => +v);
const [T, P] = input
  .shift()
  .split(" ")
  .map((v) => +v);

let minShirtsBundle = 0;

for (let shirt of shirts) {
  if (shirt % T !== 0) minShirtsBundle += 1;
  minShirtsBundle += Math.floor(shirt / T);
}

console.log(minShirtsBundle);
console.log(`${Math.floor(N / P)} ${N % P}`);
