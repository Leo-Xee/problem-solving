const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input.shift();
const strings = input;

let ret = "";
const arr = [];

const removeZeros = () => {
  while (true) {
    if (ret.length && ret.startsWith("0")) {
      ret = ret.slice(1);
    } else {
      break;
    }
  }
  if (!ret.length) ret = "0";
  arr.push(ret);
  ret = "";
};

for (let string of strings) {
  for (let c of string) {
    if (!Number.isNaN(Number.parseInt(c))) {
      ret += c;
    } else {
      if (ret.length) removeZeros();
    }
  }
  if (ret.length) removeZeros();
}

arr.sort((a, b) => {
  if (a.length === b.length) return a - b;
  return a.length - b.length;
});

for (let el of arr) {
  console.log(el);
}
