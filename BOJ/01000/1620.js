const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const mp1 = new Map();
const mp2 = new Map();

const [_, m] = input
  .shift()
  .split(" ")
  .map((v) => +v);

const quizzes = input.splice(-m);

input.forEach((v, idx) => {
  mp1.set(idx + 1, v);
  mp2.set(v, idx + 1);
});

quizzes.forEach((v) => {
  if (isNaN(Number(v))) {
    console.log(mp2.get(v));
  } else {
    console.log(mp1.get(Number(v)));
  }
});
