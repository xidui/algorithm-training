/**
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 */

var Crawler = require('crawler')
  , fs = require('fs');

var problems = {};

var c = new Crawler({
  maxConnections : 10
});

c.queue({
  uri: 'https://leetcode.com/problemset/algorithms/',
  callback: function (error, result, $) {
    var promiseList = [];
    $('#problemList').find('tr').each(function(index, problem) {
      if ($(problem).find('.fa-lock').length > 0) return;

      var id = $(problem).find('td').eq(1).text()
        , name = $(problem).find('td').eq(2).find('a').text()
        , link = $(problem).find('td').eq(2).find('a').attr('href')
        , ac = $(problem).find('td').eq(3).text()
        , difficulty = $(problem).find('td').eq(4).text();

      if (!id) return;
      if (id > 154) return;

      problems[id] = {
        id: id,
        name: name,
        link: link,
        ac: ac,
        difficulty: difficulty
      };

      setTimeout(function() {
        c.queue({
          uri: 'https://leetcode.com' + link,
          callback: function (error, result, $) {
            if (error) reject(error);
            var description = '';
            $('.question-content>p').each(function (index, elem) {
              var content = $(elem).html();
              if (content) description += '<p>' + content + '</p>';
            });
            problems[id]['description'] = description;
            console.log('Get Description of id: ' + id);
            writeFile('leetcode' + id + '.json', problems[id]);
          }
        });
      }, 300);
    });

    writeFile('leetcode.json', problems);

    function writeFile(fileName, content) {
      console.log('write file: leetcode.json');
      fs.stat('../output', function(err, stat) {
        if (err && err.errno === -2) fs.mkdirSync('../output');
        fs.writeFile('../output/' + fileName, JSON.stringify(content), function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      });
    }
  }
});