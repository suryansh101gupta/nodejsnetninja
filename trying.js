const fs = require('fs');

const folders = ['./assets', './logs', './uploads'];

folders.forEach(x => {
  if (!fs.existsSync(x)) {
    fs.mkdir(x, err => {
      if (err) {
        console.error(`Error creating ${x}:`, err);
      } else {
        console.log(`${x} created`);
      }
    });
  } else {
    fs.rmdir(x, err => {
      if (err) {
        console.error(`Error deleting ${x}:`, err);
      } else {
        console.log(`${x} deleted`);
      }
    });
  }
});
