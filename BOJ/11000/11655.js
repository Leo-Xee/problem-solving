const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString();

const ret = input.split("").map((v) => {
  const code = v.charCodeAt();

  if (code >= 65 && code <= 90) {
    if (code + 13 > 90) {
      return String.fromCharCode(code - 13);
    } else {
      return String.fromCharCode(code + 13);
    }
  }

  if (code >= 97 && code <= 122) {
    if (code + 13 > 122) {
      return String.fromCharCode(code - 13);
    } else {
      return String.fromCharCode(code + 13);
    }
  }

  return v;
});

console.log(ret.join(""));
