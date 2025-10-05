const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input.shift();
const nums = input.map(Number);

for (let num of nums) {
  let two = 0;
  let five = 0;

  for (let i = 2; i <= num; i *= 2) {
    two += Math.floor(num / i);
  }

  for (let i = 5; i <= num; i *= 5) {
    five += Math.floor(num / i);
  }

  console.log(Math.min(two, five));
}
