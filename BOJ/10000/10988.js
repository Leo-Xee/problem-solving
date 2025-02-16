const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

const a = input.shift();
const b = a.split("").reverse().join("");

if (a === b) {
  console.log(1);
} else {
  console.log(0);
}
