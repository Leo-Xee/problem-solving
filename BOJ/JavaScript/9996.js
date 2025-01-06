const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input.shift();
const pattern = input.shift();
let ret = "";

const pos = pattern.indexOf("*");
const pre = pattern.substring(0, pos);
const post = pattern.substring(pos + 1);

for (s of input) {
  if (s.length < pre.length + post.length) {
    ret += "NE\n";
    continue;
  }

  if (
    s.substring(0, pre.length) === pre &&
    s.substring(s.length - post.length) === post
  ) {
    ret += "DA\n";
  } else {
    ret += "NE\n";
  }
}

console.log(ret);
