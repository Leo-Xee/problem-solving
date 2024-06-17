const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

const solution = (input) => {
  const arr = [];
  const res = [];

  for (let v of input) {
    const [cmd, value] = v.split(" ");

    if (cmd === "push") {
      arr.push(+value);
    }

    if (cmd === "pop") {
      if (arr.length === 0) {
        res.push(-1);
      } else {
        res.push(arr.pop());
      }
    }

    if (cmd === "size") {
      res.push(arr.length);
    }

    if (cmd === "empty") {
      if (arr.length === 0) {
        res.push(1);
      } else {
        res.push(0);
      }
    }

    if (cmd === "top") {
      if (arr.length === 0) {
        res.push(-1);
      } else {
        res.push(arr[arr.length - 1]);
      }
    }
  }

  return res.join("\n");
};

input.shift();
console.log(solution(input));
