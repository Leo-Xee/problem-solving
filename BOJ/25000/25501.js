const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

input.shift();
const arr = input;

let cnt = 0;

const recursion = (str, l, r) => {
  cnt++;

  if (l >= r) return 1;
  else if (str[l] !== str[r]) return 0;
  else return recursion(str, l + 1, r - 1);
};

const isPalindrome = (str) => {
  return recursion(str, 0, str.length - 1);
};

for (let it of arr) {
  console.log(isPalindrome(it), cnt);
  cnt = 0;
}
