const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, S] = input.shift().split(" ").map(Number);
const array = input[0].split(" ").map(Number);
let cnt = 0;

const go = (current, sum) => {
  if (current === N) {
    if (sum === S) cnt++;
    return;
  }

  go(current + 1, sum);
  go(current + 1, sum + array[current]);
};

go(0, 0);

if (S === 0) cnt--;
console.log(cnt);
