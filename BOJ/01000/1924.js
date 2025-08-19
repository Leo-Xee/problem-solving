const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
const daysOfWeek = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];

let total = 0;

const [x, y] = input
  .shift()
  .split(" ")
  .map((v) => +v);

for (let i = 0; i < x; i++) total += days[i];
total += y;
console.log(daysOfWeek[total % 7]);
