const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [, ...arr] = input.map((v) => v.split(" ").map((v) => +v));

const ret = arr.sort((a, b) => {
  if (a[0] !== b[0]) return a[0] - b[0];
  return a[1] - b[1];
});

console.log(
  ret
    .map((v) => v.join(" "))
    .map((v) => v)
    .join("\n")
);
