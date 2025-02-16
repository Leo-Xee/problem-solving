```js
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "../input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");
```

```sh
g++ -std=c++14 -Wall test.cpp -o test.out
```
