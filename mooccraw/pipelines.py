# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import json
import codecs
import MySQLdbs
#from scrapy.exceptions import DropItem

class MooccrawPipeline(object):
	# def __init__(self):
	# 	self.file = open('data.json','w')

	def open_spider(self,spider):
		#print("-------------------open")
		self.file = open('data.json','w')
		self.file = codecs.open('data.json','w',encoding='utf-8')

	def close_spider(self,spider):
		self.file.close()

	def process_item(self, item, spider):
		line = json.dumps(dict(item),ensure_ascii=False) + "\n"
		self.file.write(line)
		return item