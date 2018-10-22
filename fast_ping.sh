#!/bin/bash
#Description:相对于前面的ping.sh 的脚本的利用子进程来快速执行
#
#Author: XYJ
#Version:1.0
#CreateTime:'20181012--07:46'

for ip in 192.168.227.{1..255}
do
	(
		ping $ip -c2 &> /dev/null;
		
		if [ $? -eq 0 ]
		then
			echo $ip is alive
		fi
	)&
done

wait
