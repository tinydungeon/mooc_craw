# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class MooccrawItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    #课程标题
    title = scrapy.Field()
    #课程url
    url = scrapy.Field()
    #课程图片
    image_url = scrapy.Field()
    #课程描述
    introduce = scrapy.Field()
    #课程学习人数
    student_num = scrapy.Field()
    #课程标签
    catycray = scrapy.Field()
    # #课程难度
    degree = scrapy.Field()
    # #课程时长
    hour = scrapy.Field()
    #课程评分
    score = scrapy.Field()
    
