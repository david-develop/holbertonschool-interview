#!/usr/bin/node

const request = require('request');
const urlApi = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

const promisifiedRequest = function (options) {
  return new Promise((resolve, reject) => {
    request(options, (error, response, body) => {
      if (response) {
        return resolve(response);
      }
      if (error) {
        return reject(error);
      }
    });
  });
};

request(urlApi, function (error, response, body) {
  if (error) {
    console.error(error); // Print the error if one occurred
    return;
  }
  const jsonRes = JSON.parse(body);
  const charUrl = jsonRes.characters;
  (async function () {
    for (let i = 0; i < charUrl.length; i++) {
      const options = {
        url: charUrl[i],
        method: 'GET'
      };

      const response = await promisifiedRequest(options);

      console.log(JSON.parse(response.body).name);
    }
  })();
});
