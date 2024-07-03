const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

const N = +input.shift();
const sequence = input.map((i) => +i);

const solution = (N, sequence) => {
  const stack = [];
  let res = "";
  let current = 1;
  let isPossible = true;

  for (let i = 1; i <= N; i++) {
    while (current <= sequence[i - 1]) {
      stack.push(current);
      res += "+\n";
      current++;
    }

    if (stack[stack.length - 1] === sequence[i - 1]) {
      stack.pop();
      res += "-\n";
    } else {
      isPossible = false;
      break;
    }
  }

  return isPossible ? res : "NO";
};

console.log(solution(N, sequence));
