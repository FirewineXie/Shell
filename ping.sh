#!/bin/bash
#Description:根据网络配置对网络地址192.168.0进行修改
#
#Author: XYJ
#Version:1.0
#CreateTime:'20181012--07:41'

for  ip in 192.168.227.{1..255}
do
	ping $ip -c 2 &> /dev/null;
	
	if [ $? -eq 0 ]
	then
		echo $ip is alive
	fi
done
