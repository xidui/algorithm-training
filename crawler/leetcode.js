var Crawler = require("crawler");
var url = require('url');

var c = new Crawler({
  maxConnections : 10,
  // This will be called for each crawled page
  callback : function (error, result, $) {
    $('#problemList').find('tr').each(function(index, problem) {
      if ($(problem).find('.fa-lock').length > 0) return;
      var id = $(problem).find('td').eq(1).text()
        , name = $(problem).find('td').eq(2).find('a').text()
        , link = $(problem).find('td').eq(2).find('a').attr('href')
        , ac = $(problem).find('td').eq(3).text()
        , difficulty = $(problem).find('td').eq(4).text();
      console.log(id, name, link, ac, difficulty);
    })
  }
});

c.queue('https://leetcode.com/problemset/algorithms/');