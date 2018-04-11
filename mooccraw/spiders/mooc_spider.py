# -*- coding: utf-8 -*-
import scrapy
import urllib
from mooccraw.items import MooccrawItem

class MoocSpider(scrapy.Spider):
    name = "mooc_spider"
    #allowed_domains = ["imooc.com"]
    #start_urls = ["http://www.imooc.com/course/list"]

    def start_requests(self):
         for x in range(1,2):
            page='http://www.imooc.com/course/list?page='+str(x)
            yield scrapy.Request(page, callback=self.parse1)
    
    def parse1(self,response):
        item = MooccrawItem()
        for box in response.xpath('//div[@class="course-card-container"]'):
            # print("-----------------------------box: ", box)
            item['title'] = box.xpath('.//h3/text()').extract()[0]
            # print("-----------------------------title: ", item['title'])
            item['url'] = 'http://www.imooc.com'+box.xpath('.//@href').extract()[0]
            item['image_url'] = box.xpath('.//@src').extract()[0]
            item['introduce'] = box.xpath('.//p/text()').extract()[0].strip()
            item['student_num'] = box.xpath('.//div[@class="course-card-info"]/span[2]/text()').extract()[0]
            #±êÇ©,¿ÉÄÜ»áÓÐ1µ½3¸ö
            if len(box.xpath('.//div[@class="course-label"]/label/text()').extract()) == 1:
                item['catycray'] = box.xpath('.//div[@class="course-label"]/label/text()').extract()[0]
            elif len(box.xpath('.//div[@class="course-label"]/label/text()').extract()) == 2:
                item['catycray'] = box.xpath('.//div[@class="course-label"]/label/text()').extract()[0] + ' ' + box.xpath('.//div[@class="course-label"]/label/text()').extract()[1]
            elif len(box.xpath('.//div[@class="course-label"]/label/text()').extract()) == 3:
                item['catycray'] = box.xpath('.//div[@class="course-label"]/label/text()').extract()[0] + ' ' + box.xpath('.//div[@class="course-label"]/label/text()').extract()[1] + ' '+ box.xpath('.//div[@class="course-label"]/label/text()').extract()[2]
            else:
                item['catycray'] = ''
            
            # item['degree'] = box.xpath('.//div[@class="course-card-info"]/span[1]/text()').extract()[0]
            #'title':item['title']
            #yield scrapy.Request(item['url'],callback = self.parseNext,meta = item)
            yield scrapy.Request(item['url'],callback = self.parseNext,meta =item)
            #print(item['title'])
            
           
            
    def parseNext(self,response):
        #print('-----------------------------meta: ', response.meta['title'])

        item = response.meta
        #print('-----------------------------meta: ', item['title'])
        #item['title'] = response.meta['title']


        item['degree'] = response.xpath('.//div[@class="static-item l"]/span[@class="meta-value"]/text()').extract()[0]
        item['hour'] =response.xpath('.//div[@class="static-item l"]/span[@class="meta-value"]/text()').extract()[1]
        item['score']=response.xpath('.//div[@class="static-item l score-btn"]/span[@class="meta-value"]/text()').extract()[0]

        #print("-----------------------------title: ", item['title'])
        yield item
        
        
        
        