const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input[0];

const arr = Array.from({ length: 15 }).fill(0);
let ret = 0;

const go = (current) => {
  if (current === N) {
    return ret++;
  }

  for (let i = 0; i < N; i++) {
    arr[current] = i;
    let isPossible = true;

    for (let j = 0; j < current; j++) {
      if (
        arr[current] === arr[j] ||
        Math.abs(arr[current] - arr[j]) === current - j
      ) {
        isPossible = false;
        break;
      }
    }

    if (isPossible) go(current + 1);
  }
};

go(0);
console.log(ret);
