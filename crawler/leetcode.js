var Crawler = require("crawler");
var problems = {};

var c = new Crawler({
  maxConnections : 10
});

c.queue({
  uri: 'https://leetcode.com/problemset/algorithms/',
  callback: function (error, result, $) {
    $('#problemList').find('tr').each(function(index, problem) {
      if ($(problem).find('.fa-lock').length > 0) return;
      var id = $(problem).find('td').eq(1).text()
        , name = $(problem).find('td').eq(2).find('a').text()
        , link = $(problem).find('td').eq(2).find('a').attr('href')
        , ac = $(problem).find('td').eq(3).text()
        , difficulty = $(problem).find('td').eq(4).text();
      problems[id] = {
        id: id,
        name: name,
        link: link,
        ac: ac,
        difficulty: difficulty
      };

      c.queue({
        uri: 'https://leetcode.com' + link,
        callback: function (error, result, $) {
          var description = '';
          $('.question-content>p').each(function(index, elem) {
            var content = $(elem).html();
            if (content) description += '<p>' + content + '</p>';
          });
          problems[id]['description'] = description;
          console.log(problems[id]['description']);
        }
      });
    });
  }
});