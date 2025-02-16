const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

input.shift();

const solution = (input) => {
  const result = [];

  for (const sentence of input) {
    const words = sentence.split(" ");

    for (const word of words) {
      const stack = [];

      for (const letter of word) {
        stack.push(letter);
      }

      for (_ of word) {
        result.push(stack.pop());
      }

      result.push(" ");
    }
    result.push("\n");
  }

  return result.join("");
};

console.log(solution(input));
