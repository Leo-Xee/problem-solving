const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

let Y = 0;
let M = 0;

input.shift();
const costs = input[0].split(" ").map((v) => +v);

costs.forEach((cost) => {
  Y += Math.floor(cost / 30 + 1) * 10;
  M += Math.floor(cost / 60 + 1) * 15;
});

if (Y === M) console.log("Y M", Y);
if (Y > M) console.log("M", M);
if (Y < M) console.log("Y", Y);
