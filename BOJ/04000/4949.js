const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

for (let line of input) {
  let st = [];
  let isBalenced = true;

  if (line === ".") break;

  for (let char of line) {
    if (char === "(" || char === "[") st.push(char);

    if (char === ")") {
      if (st.length === 0 || st[st.length - 1] !== "(") {
        isBalenced = false;
        break;
      }
      st.pop();
    }

    if (char === "]") {
      if (st.length === 0 || st[st.length - 1] !== "[") {
        isBalenced = false;
        break;
      }
      st.pop();
    }
  }

  console.log(isBalenced && st.length === 0 ? "yes" : "no");
}
