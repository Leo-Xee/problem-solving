const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const isVowel = (c) => {
  return "aeiou".includes(c);
};

while (true) {
  const s = input.shift();

  if (s === "end") break;

  let success = 1;
  let vowelCnt = 0;
  let consonantCnt = 0;
  let hasVowel = 0;
  let prev = -1;

  for (let i = 0; i < s.length; i++) {
    let c = s[i];

    if (isVowel(c)) {
      vowelCnt++;
      consonantCnt = 0;
      hasVowel = 1;
    } else {
      consonantCnt++;
      vowelCnt = 0;
    }

    if (vowelCnt === 3 || consonantCnt === 3) success = 0;

    if (i > 0 && prev === c && c !== "e" && c !== "o") {
      success = 0;
    }
    prev = c;
  }

  if (!hasVowel) success = 0;
  if (success) {
    console.log(`<${s}> is acceptable.`);
  } else {
    console.log(`<${s}> is not acceptable.`);
  }
}
