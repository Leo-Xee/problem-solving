const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const s = input[0];
const cnt = Array.from({ length: 26 }).fill(0);
let ret = "";
let mid = "";
let fail = 0;

for (let i = 0; i < s.length; i++) {
  cnt[s[i].charCodeAt() - "A".charCodeAt()]++;
}

for (let i = "Z".charCodeAt(); i >= "A".charCodeAt(); i--) {
  const idx = i - "A".charCodeAt();

  if (cnt[idx]) {
    if (cnt[idx] % 2 === 1) {
      fail++;
      mid = String.fromCharCode(i);
      cnt[idx]--;
    }
  }

  if (fail === 2) break;

  for (let j = 0; j < cnt[idx]; j += 2) {
    ret = String.fromCharCode(i) + ret + String.fromCharCode(i);
  }
}

if (mid) {
  let midIdx = Math.floor(ret.length / 2);
  ret = ret.slice(0, midIdx) + mid + ret.slice(midIdx);
}

if (fail == 2) {
  console.log("I'm Sorry Hansoo");
} else {
  console.log(ret);
}
