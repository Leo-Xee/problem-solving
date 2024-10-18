const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs
  .readFileSync(filePath)
  .toString()
  .trim()
  .split("\n")
  .map((v) => +v);

function solution(arr) {
  let total = arr.reduce((p, c) => p + c, 0);

  for (let i = 0; i < 8; i++) {
    for (let j = i + 1; j < 9; j++) {
      if (total - arr[i] - arr[j] === 100) {
        const ret = arr.filter((v) => v !== arr[i] && v !== arr[j]);
        return ret;
      }
    }
  }
}

solution(input)
  .sort((a, b) => a - b)
  .forEach((v) => console.log(v));
