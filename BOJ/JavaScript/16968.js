const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString();

function solution(str) {
  let cnt = 1;

  for (let i = 0; i < str.length; i++) {
    if (str[i] === "d") {
      if (str[i] === str[i - 1]) {
        cnt *= 9;
      } else {
        cnt *= 10;
      }
    }

    if (str[i] === "c") {
      if (str[i] === str[i - 1]) {
        cnt *= 25;
      } else {
        cnt *= 26;
      }
    }
  }

  return cnt;
}

console.log(solution(input));
