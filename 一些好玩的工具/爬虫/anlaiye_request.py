'''
Author: your name
Date: 2022-04-09 17:46:38
LastEditTime: 2022-04-09 20:15:09
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: /Code/Silicon-Vallery/一些好玩的工具/爬虫/anlaiye_request.py
'''
import requests as rq
import random
import time

shop_id = 12807  # 填写商店的id, 一楼炸鸡面包房的shop_id是26481，二楼汉堡店的是12805，厝内小眷村的是12807
bark_id = "https://api.day.app/EJoDWBqWEUYGgPAjpeuZFG"  # 填写你的bark id，可以到apple store搜索bark软件获取bark id
token = "55_U5JJCDzgNwp_W-4f03jUmXTg2_pIeEgBmOnw4rM1hAOZoIgacJjo-ORrxzyzqLvO6Jds8gPdKhgvNMKGdNKXgMgwMwA9Hdu2ov1ao0sKe-Oc3xymM3XKLiFSHR-CBWJG20eTGDF2UBezk5vjEOWhABAAKS"  # 换成自己的token，抓包观察请求头即可看到
device_id = "55_U5JJCDzgNwp_W-4f03jUmXTg2_pIeEgBmOnw4rM1hAOZoIgacJjo-ORrxzyzqLvO6Jds8gPdKhgvNMKGdNKXgMgwMwA9Hdu2ov1ao0sKe-Oc3xymM3XKLiFSHR-CBWJG20eTGDF2UBezk5vjEOWhABAAKS"  # 换成自己的token，抓包观察请求头即可看到
login_token = "55_U5JJCDzgNwp_W-4f03jUmXTg2_pIeEgBmOnw4rM1hAOZoIgacJjo-ORrxzyzqLvO6Jds8gPdKhgvNMKGdNKXgMgwMwA9Hdu2ov1ao0sKe-Oc3xymM3XKLiFSHR-CBWJG20eTGDF2UBezk5vjEOWhABAAKS"  # 换成自己的token，抓包观察请求头即可看到

head = {
    "accept": "application/json, text/plain, */*",
    "content-type": "application/x-www-form-urlencoded",
    "origin": "https://alywechat.anlaiye.com",
    "accept-language": "zh-CN,zh-Hans;q=0.9",
    "user-agent Mozilla/5.0": "(iPhone; CPU iPhone OS 15_0 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Mobile/15E148 MicroMessenger/8.0.18(0x1800123f) NetType/WIFI Language/zh_CN"
                              "accept-encoding" "gzip, deflate, br"
}

url = "https://web-agent.anlaiye.com/agent/postV3"
data = {"app_version": "8.1.5",
        "target": "merchants",
        "action": "/pub/shop/goodsV2",
        "token": token,
        "device_id": device_id,
        "login_token": login_token,
        "shop_id": shop_id}


def notify(barker_id="", msg=""):
    rq.get("https://api.day.app/%s/%s/" % (barker_id, msg))


def check():
    response = rq.post(url, headers=head, data=data)
    if response.status_code == 200:
        return response.json()
    else:
        return None


def check_stock(dat: dict):
    shop = dat['data']['shop_detail']['shop_name']
    if dat['data']['shop_detail']['is_open'] == "0":
        return False, shop + "未开放"
    for item in dat['data']['item_list']:
        for good in item['goods_list']:
            if good["stock"] > 0:
                return True, shop + good['tag_name'] + "有货"
    return False, shop + "开放，但是没有商品有货"


def main():
    while True:
        res = check()
        if not res:
            print("检测失败")
            break
        else:
            cres, msg = check_stock(res)
            print(msg)
            if cres:
                notify(bark_id, msg)
        rand_sleep = (random.random() * 16 + 15) % 10 + 10
        print("沉睡 %.2f 秒" % rand_sleep)
        time.sleep(rand_sleep)


if __name__ == '__main__':
    main()
