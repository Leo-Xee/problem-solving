const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = Number(input.shift());

input.forEach((v) => {
  const cnt = Array.from({ length: 26 }).fill(0);
  let isPossible = true;

  const [a, b] = v.split(" ");

  a.split("").forEach((v) => {
    cnt[v.charCodeAt() - "a".charCodeAt()]++;
  });

  b.split("").forEach((v) => {
    cnt[v.charCodeAt() - "a".charCodeAt()]--;
  });

  cnt.forEach((v) => {
    if (v !== 0) isPossible = false;
  });

  if (isPossible) console.log("Possible");
  else console.log("Impossible");
});
