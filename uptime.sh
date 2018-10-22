#!/bin/bash
#Description: 系统运行时间监视器
#
#Author: XYJ
#Version:1.0
#CreateTime:'20181013--06:28'

IP_LIST="192.168.227.128"
USER="root"

for IP in $IP_LIST;
do
	utime=$(ssh ${USER}@${IP} uptime | awk '{ print $3 } ')
	echo $IP uptime: $utime
done
