const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().split("\n");

const T = +input.shift();

const solution = (T, arr) => {
  const ret = [];

  for (let i = 0; i < T; i++) {
    const s = arr[i];
    let cnt = 0;

    for (let j = 0; j < s.length; j++) {
      if (s[j] === "(") {
        cnt++;
      } else {
        cnt--;
        if (cnt < 0) {
          ret.push("NO");
          break;
        }
      }
    }

    if (cnt == 0) {
      ret.push("YES");
    } else if (cnt > 0) {
      ret.push("NO");
    }
  }

  return ret.join("\n");
};

console.log(solution(T, input));
